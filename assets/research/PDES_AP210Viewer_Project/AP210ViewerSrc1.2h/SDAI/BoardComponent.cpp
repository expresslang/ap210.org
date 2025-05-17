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

#include "BoardComponent.h"
#include "MountingRestrictionArea.h"
#include "NonPlatedThruHole.h"
#include "../PWBDataBase.h"
#include "ExtractGeometry.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
BoardComponent *BoardComponent::Construct(PWBDataBase *PWBdatabase,
                                          SdaiModel AP210Model,
                                          SdaiAppInstance PWBpu) {
   AP210ObjectList *lines;
   BoardComponent *bc = NULL;
   // should document which UoF the shape rep comes from. MTK 11/19/2000
   SdaiAppInstance BoardShapeRep = getInterconnectModuleEdgeShapeRep(AP210Model, PWBpu);
   // Build with 'physical design usage' view inorder to pickup PWB thickness.
   SdaiAppInstance PWBpdu = PWBdatabase->getInterconnectModulePhysicalDesignUsage();

#ifdef VERBOSE
   TRACE("BoardComponent::Construct()\r\n");
#endif
   if (BoardShapeRep == sdaiNULL) {
#ifdef VERBOSE
   TRACE("Looking for Interconnect module edge surface.\r\n");
#endif
      BoardShapeRep = getInterconnectModuleEdgeSurfaceShapeRep(AP210Model, PWBpdu);
      }
#ifdef VERBOSE
   TRACE("   PWBpu (physical design): %s\r\n", _sdaiGetPart21Description(PWBpu));
   TRACE("   PWBpdu (physical design usage): %s\r\n", _sdaiGetPart21Description(PWBpdu));
   TRACE("   BoardShapeRep: %s\r\n", _sdaiGetPart21Description(BoardShapeRep));
#endif
   if (BoardShapeRep != sdaiNULL) { 
       lines = ExtractGeometry::getLines(AP210Model, PWBdatabase,
                                         getGeometryFromShapeRep(AP210Model, BoardShapeRep),
                                         getRepresentationLengthUnit(AP210Model, BoardShapeRep)
                                         );
       bc = new BoardComponent(PWBdatabase, AP210Model, PWBpu, PWBpdu, lines);
      }
#ifdef VERBOSE
   else {
       TRACE("NO BOARD SHAPE FOUND!\r\n");
       }
   TRACE("Leaving: BoardComponent::Construct()\r\n");
#endif
   return bc;
   }
#define VERBOSE
BoardComponent::BoardComponent(PWBDataBase *PWB,
                               SdaiModel AP210Model,
                               SdaiAppInstance PWBpd,
                               SdaiAppInstance PWBpdu,
                               AP210ObjectList *lines):
ComponentDefinition(PWB, PWBpdu, lines) {
#ifdef USEPWBNAME
   static SdaiEntity PU = sdaiGetEntity(AP210Model, "physical_unit");
   static SdaiAttr PU_ID = sdaiGetAttrDefinition(PU, "id");
#endif
   static SdaiEntity P = sdaiGetEntity(AP210Model, "product");
   static SdaiAttr P_ID = sdaiGetAttrDefinition(P, "id");

   SdaiAppInstance PWBp;  // interconnect module product
   SdaiString PWBp_id;    // product.id

#ifdef USEPWBNAME
   SdaiString PWBpu_id;
#endif
   SdaiAppInstance cd; // interconnect modules component_defintion
   SdaiNPL mraList = sdaiCreateNPL();
   SdaiNPL npthList = sdaiCreateNPL();

#ifdef VERBOSE
   TRACE("In BoardComponent::BoardComponent()\r\n");
   TRACE("   pu (physical design usage): %s\r\n", _sdaiGetPart21Description(PWBpdu));
#endif
#ifdef USEPWBNAME
   sdaiGetAttr(PWBpdu, PU_ID, sdaiSTRING, &PWBpu_id);
   Name = strdup(PWBpu_id);
#endif
   PhysicalDesignRef = PWBpd;   
   PhysicalDesignUsageRef = PWBpdu;   
#ifdef VERBOSE
   TRACE("Looking for Mounting Restriction Areas\n");
#endif
   cd = getInterconnectModuleComponentDefinition(AP210Model, PWBpdu);
#ifdef VERBOSE
   TRACE("   cd (interconnect module): %s\r\n", _sdaiGetPart21Description(cd));
#endif

   getMountingRestrictionAreas(AP210Model, mraList, cd);
#ifdef VERBOSE
   if (sdaiGetMemberCount(mraList) > 0) {
      SdaiInstance mra;   // mounting_restriction_area
      SdaiIterator mra_itor = sdaiCreateIterator(mraList);

      while (sdaiNext(mra_itor)) {
         sdaiGetAggrByIterator(mra_itor, sdaiINSTANCE, &mra); 
          TRACE("mounting_restriction_area: %s\r\n", _sdaiGetPart21Description(mra));
         }
      sdaiDeleteIterator(mra_itor);
      }
#endif
   MountingRestrictionArea::Construct(PWB, mraList);
   sdaiDeleteNPL(mraList);

#ifdef VERBOSE
   TRACE("Looking for drilled holes\r\n");
#endif
   getDrilledHoles(AP210Model, npthList);
#ifdef VERBOSE
   if (sdaiGetMemberCount(npthList) > 0) {
      SdaiInstance npth;   // mounting_restriction_area
      SdaiIterator npth_itor = sdaiCreateIterator(npthList);

      while (sdaiNext(npth_itor)) {
         sdaiGetAggrByIterator(npth_itor, sdaiINSTANCE, &npth); 
          TRACE("non-plated thru-hole: %s\r\n", _sdaiGetPart21Description(npth));
         }
      sdaiDeleteIterator(npth_itor);
      }
#endif
   NonPlatedThruHole::Construct(PWB, npthList);
   sdaiDeleteNPL(npthList);

   PWBp = PWB->getAssembliesInterconnectModuleProduct();
#ifdef VERBOSE
TRACE("PWBp: %s\r\n", _sdaiGetPart21Description(PWBp));
#endif
   if (PWBp != sdaiNULL) {
      sdaiGetAttr(PWBp, P_ID, sdaiSTRING, &PWBp_id);
      ComponentDefinition::setName(PWBp_id);
      }
#ifdef VERBOSE
   TRACE("Leaving BoardComponent::BoardComponent()\r\n");
#endif
   } 
#undef VERBOSE
BoardComponent::~BoardComponent() {
   } 
int BoardComponent::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return ComponentDefinition::DynamicType(ID);
   }
#ifdef INSTANCEOF
BoardComponent *BoardComponent::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(BoardComponent *)s;
   return 0;
   }
BoardComponent *BoardComponent::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(BoardComponent *)s;
   return 0;
   }
#endif
void BoardComponent::ReDraw(double Z, double Base) {
	AP210GraphicObject::ReDraw(getConstructionThickness(), Base);
   }
void BoardComponent::Draw(double Base) {
	AP210GraphicObject::Draw(getConstructionThickness(), Base);
   }

double BoardComponent::getConstructionThickness() {
   double thickness = getThickness();

   if (thickness < 0.001) {
      return 0.001; // Handles the problem of to thin a board for OpenGL
      }
   return thickness;
   }

double BoardComponent::getThickness() {
   return getPCBThickness(DataBase->AP210Model, PhysicalDesignUsageRef);
   }

void BoardComponent::setThickness(double thickness) {

   if (getPCBThickness(DataBase->AP210Model, PhysicalDesignUsageRef) != thickness) {
      setPCBThickness(DataBase->AP210Model, PhysicalDesignUsageRef, thickness);
      setReDrawStatus();
      DataBase->SetModifiedFlag(TRUE);
      }
   }
/*
In BoardComponent::buildDrilledHoles()
PhysicalUnitRef: #246 a physical_unit  Value = 0-0
count: 2
pc: #212 a component_definition  Value = 0-0
pc: #247 a physical_unit  Value = 0-0
Leaving BoardComponent::buildDrilledHoles()
*/
void BoardComponent::getDrilledHoles(SdaiModel AP210Model, SdaiNPL npthList) {
   static SdaiEntity NAUO = sdaiGetEntity(AP210Model, "next_assembly_usage_occurrence");

   // component
   static SdaiAttr NAUO_ED = sdaiGetAttrDefinition(NAUO, "related_product_definition");
   // PWApu
   static SdaiAttr NAUO_ING = sdaiGetAttrDefinition(NAUO, "relating_product_definition");

   static SdaiEntity CD = sdaiGetEntity(AP210Model, "component_definition");
   static SdaiAttr CD_DESC = sdaiGetAttrDefinition(CD, "description");

   SdaiNPL domain = sdaiCreateNPL();
   SdaiNPL resultList = sdaiCreateNPL();
   SdaiAppInstance nauo;
   SdaiString desc;

   SdaiIterator itor;
   SdaiAppInstance cd;    // component_definition
   SdaiIterator npthitor = sdaiCreateIterator(npthList);

#ifdef VERBOSE
TRACE0("In BoardComponent::getDrilledHoles()\r\n");
#endif
   // create an iterator for all the instances
   // change to all the nauo that have a usedin to PWApu
   sdaiFindInstanceUsedIn(PhysicalDesignRef, NAUO_ING, domain, resultList);

#ifdef VERBOSE
TRACE("count: %d\n", sdaiGetMemberCount(resultList));
#endif
   if (sdaiGetMemberCount(resultList) > 0) {
      itor = sdaiCreateIterator(resultList);
      while (sdaiNext(itor)) {
         sdaiGetAggrByIterator(itor, sdaiINSTANCE, &nauo); 
         sdaiGetAttr(nauo, NAUO_ED, sdaiINSTANCE, &cd);
         sdaiGetAttr(cd, CD_DESC, sdaiSTRING, &desc);
         if (!strcmp("non-plated thru-hole", desc)) {
#ifdef VERBOSE
TRACE0("Found a Drilled Hole!\r\n");
TRACE("cd: %s\r\n", _sdaiGetPart21Description(cd));
TRACE(" desc: %s\r\n", desc);
#endif
            sdaiEnd(npthitor);
            sdaiInsertBefore(npthitor, sdaiINSTANCE, cd);
            }
         }   
      sdaiDeleteIterator(itor);
      }
   sdaiDeleteNPL(domain);
   sdaiDeleteNPL(resultList);
   sdaiDeleteIterator(npthitor);
#ifdef VERBOSE
TRACE0("Leaving BoardComponent::getDrilledHoles()\r\n");
#endif
   }

void BoardComponent::setName(CString name) {
   static SdaiEntity P = sdaiGetEntity(DataBase->AP210Model, "product");
   static SdaiAttr P_ID = sdaiGetAttrDefinition(P, "id");

   SdaiAppInstance PWBp;  // interconnect module product

   PWBp = DataBase->getAssembliesInterconnectModuleProduct();
#ifdef VERBOSE
TRACE("PWBp: %s\r\n", _sdaiGetPart21Description(PWBp));
#endif
   if (PWBp != sdaiNULL) {
      DataBase->SetModifiedFlag(TRUE);
      sdaiPutAttr(PWBp, P_ID, sdaiSTRING, name);
      ComponentDefinition::setName(name);
      }
   }
