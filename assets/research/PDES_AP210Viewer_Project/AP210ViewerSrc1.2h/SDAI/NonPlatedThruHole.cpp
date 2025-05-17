/*
 * $Id:$
 * Auth: Michael T. Keenan
 * 
 * This class is an artifact of the Material test routine and should be
 * elemenated.
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>
#include <sdai.h>

#include "SdaiUtility.h"
#include "SdaiStoredProceedures.h"

#include "NonPlatedThruHole.h"
#include "BoardComponent.h"
#include "../PWBDataBase.h"
#include "ExtractGeometry.h"

//
#include "ap210_visualizer.h"
#include "AP210MagicStrings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#ifdef VERBOSE
#include "..\OpenGL\MatrixUtilities.h"
#endif
void NonPlatedThruHole::Construct(PWBDataBase *PWB,
                                  SdaiNPL npthList) {
#ifdef VERBOSE
   TRACE("In NonPlatedThruHole::Construct\r\n");
   TRACE("%d NPTHs\r\n", sdaiGetMemberCount(npthList));
#endif
   if (sdaiGetMemberCount(npthList) > 0) {
      NonPlatedThruHole *newnpth;
      SdaiInstance npth;   // non-plated thru-hole
      SdaiIterator npth_itor = sdaiCreateIterator(npthList);

      while (sdaiNext(npth_itor)) {
         sdaiGetAggrByIterator(npth_itor, sdaiINSTANCE, &npth); 
#ifdef VERBOSE
         TRACE("non-plated thru-hole: %s\r\n", _sdaiGetPart21Description(npth));
#endif
         if ((newnpth = Construct(PWB, npth)) != sdaiNULL) {
            PWB->NonPlatedThruHoles.Add(newnpth);
#ifdef VERBOSE
            TRACE("%d NonPlatedThruHoles\r\n", PWB->NonPlatedThruHoles.SizeOf()); 
#endif
            }
         }
      sdaiDeleteIterator(npth_itor);
      }
   }
// need to add some validity checking here.

NonPlatedThruHole *NonPlatedThruHole::Construct(PWBDataBase *PWBdatabase,
                                                SdaiAppInstance npth) {
   SdaiAppInstance pcasr = sdaiNULL; // packaged_component analysis shape_representation
   SdaiAppInstance A2P_LOC; // packaged_component location
   SdaiAppInstance unit;
   NonPlatedThruHole *mpc = NULL;
   SdaiModel AP210Model = PWBdatabase->AP210Model;

   /* get component specific information */ 
   A2P_LOC = getPackagedComponentLocation(AP210Model, npth);
#ifdef VERBOSE
TRACE("component_location: %s\r\n", _sdaiGetPart21Description(A2P_LOC));
#endif
   // Get the packaged_components shape_representation.
   pcasr = sdaiNULL;  // required only if you comment out the line below.
   pcasr = getComponentGeometry(AP210Model, npth);
#ifdef VERBOSE
TRACE("pcasr 1: %s\r\n", _sdaiGetPart21Description(pcasr));
#endif
   if (pcasr == sdaiNULL) {
      // Look for rockwell shape_representations here.
      pcasr = getComponentDefinitionShapeRepresentation(AP210Model, npth);
#ifdef VERBOSE
TRACE("pcasr 2: %s\r\n", _sdaiGetPart21Description(pcasr));
#endif
      }

   if (pcasr != sdaiNULL) {
      // get the shape representations length units
      // this unit is used A2P_LOC, it might not be correct!!!!
      if ((unit = getRepresentationLengthUnit(AP210Model, pcasr)) == sdaiNULL) {
         TRACE("ERROR: &s\r\n       has no units.\r\n", _sdaiGetPart21Description(pcasr));
         }     
#ifdef VERBOSE
TRACE("unit: %s\r\n", _sdaiGetPart21Description(unit));
#endif
      // get the lines from the shape rep
      AP210ObjectList *lines = ExtractGeometry::getLines(AP210Model, PWBdatabase, 
                                                         getGeometryFromShapeRep(AP210Model, pcasr),
                                                         unit);
         // create a listof points
//      getPoints(lines);
      mpc = new NonPlatedThruHole(PWBdatabase, npth, lines, unit, A2P_LOC);
      }
   return mpc;
   }
NonPlatedThruHole::NonPlatedThruHole(PWBDataBase *PWB,
                                     SdaiAppInstance pc,
                                     AP210ObjectList *lines,
                                     SdaiAppInstance unit,
                                     SdaiAppInstance A2P_LOC):
ComponentDefinition(PWB, pc, lines) {
   // save the component_location and unit;
   ComponentLocationRef = A2P_LOC;
   ComponentUnitRef = unit;

#ifdef VERBOSE
TRACE("In NonPlatedThruHole::NonPlatedThruHole\r\n");
TRACE("ComponentLocationRef: 0x%08x\r\n", ComponentLocationRef);
#endif
   // get the side
   if (ComponentLocationRef != sdaiNULL) {
      char *tempside = strdup(DataBase->getPackagedComponentSurface(ComponentLocationRef));
#ifdef VERBOSE
TRACE("Surface: %s\r\n", tempside);
#endif
      if (!strcmp(PRIMARY_SURFACE, tempside)) {
         Side = Top;
         } 
      else if (!strcmp(SECONDARY_SURFACE, tempside)) {
         Side = Bottom;
         }
      else {
         Side = Unplaced;
         }
      free(tempside);
      }
   else {
      Side = Unplaced;
      }
   // get the transformation matrix
   DataBase->getTransformationMatrix(m, ComponentLocationRef, ComponentUnitRef);

#ifdef VERBOSE
TRACE("Leaving NonPlatedThruHole::NonPlatedThruHole\r\n*******\r\n");
#endif
  } 
#undef VERBOSE
NonPlatedThruHole::~NonPlatedThruHole() {
   } 
int NonPlatedThruHole::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return ComponentDefinition::DynamicType(ID);
   }
#ifdef INSTANCEOF
NonPlatedThruHole *NonPlatedThruHole::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(NonPlatedThruHole *)s;
   return 0;
   }
NonPlatedThruHole *NonPlatedThruHole::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(NonPlatedThruHole *)s;
   return 0;
   }
#endif
void NonPlatedThruHole::ReDraw(double Z, double Base) {
	AP210GraphicObject::ReDraw(getConstructionThickness(), Base);
   }
// Below I'm adding 0.0001 and 0.0002 so that the
// Below I'm adding 0.0005 and 0.0010 so that the (For NT)
// drilled whole is extends beyond the surface interconnect module.
void NonPlatedThruHole::Draw(double Base) {
#ifdef VERBOSE
TRACE0("In NonPlatedThruHole::Draw()\r\nPoints:\r\n");
TracePoints();
TRACE0("\r\n");
#endif
	AP210GraphicObject::Draw(getConstructionThickness(), Base+0.0005);
   }

double NonPlatedThruHole::getConstructionThickness() {
   return -(DataBase->PWB->getConstructionThickness()+0.0010);
   }

double NonPlatedThruHole::getThickness() {
   return -(DataBase->PWB->getThickness()+0.0010);
   }

void NonPlatedThruHole::setThickness(double thickness) {

   if (getPCBThickness(DataBase->AP210Model, PhysicalDesignUsageRef) != thickness) {
      setPCBThickness(DataBase->AP210Model, PhysicalDesignUsageRef, thickness);
      setReDrawStatus();
      DataBase->SetModifiedFlag(TRUE);
      }
   }
