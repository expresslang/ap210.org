/*
 * $Id:$
 * Auth: Michael T. Keenan
 * 
 */
#include "stdafx.h"

// the precompiled directive above most likely means
// that many of the includes below are no longer required
#include <stdlib.h>
#include <string.h>
#include <sdai.h>
#include <math.h>

// SDAI
#include "SdaiUtility.h"
#include "SdaiStoredProceedures.h"
#include "AP210MagicStrings.h"

// OpenGL
#include "../OpenGl/MatrixUtilities.h"

#include "PackagedComponent.h"
#include "../PWBDataBase.h"
#include "../AP210ViewerView.h"
#include "ExtractGeometry.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// For AP210
PackagedComponent::PackagedComponent(PWBDataBase *PWB,
                                     SdaiAppInstance pc,
                                     SdaiAppInstance unit,
                                     SdaiAppInstance A2P_LOC):
ComponentDefinition(PWB, pc) {
   static SdaiEntity nauo_entity = sdaiGetEntity(DataBase->AP210Model,
                                                "next_assembly_usage_occurrence");
   static SdaiAttr rpd = sdaiGetAttrDefinition(nauo_entity,
                                               "related_product_definition");
   static SdaiAttr rd = sdaiGetAttrDefinition(nauo_entity,
                                              "reference_designator");
   SdaiString refdes;
   
   // save the component_location and unit;
   ComponentLocationRef = A2P_LOC;
   ComponentUnitRef = unit;

#ifdef VERBOSE
TRACE("In PackagedComponent::PackagedComponent\r\n");
#endif
   // get the side
   if (ComponentLocationRef != sdaiNULL) {
      char *tempside = strdup(DataBase->getPackagedComponentSurface(ComponentLocationRef));

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

   // build the packaged_part
   PackagedPartRef = PackagedPart::Construct(PWB,
                                             getPackagedComponentPackagedPart(DataBase->AP210Model, pc));
   ItemFindNumber = PackagedPartRef->ItemFindNumber;

   // get the package
   PackageRef = PackagedPartRef->PackageRef;

   // get the reference designator 
   NauoRef = _sdaiFindSingleSubTypeInstanceUsedIn(pc, nauo_entity, rpd);
   sdaiGetAttr(NauoRef, rd, sdaiSTRING, &refdes);
   setName(refdes);

#ifdef VERBOSE
TRACE("Leaving PackagedComponent::PackagedComponent\r\n*******\r\n");
#endif
   } 

PackagedComponent::~PackagedComponent() {
   } 
int PackagedComponent::DynamicType(int ID) {
   if (ID == typeID) return 1;
   return ComponentDefinition::DynamicType(ID);
   }

#ifdef INSTANCEOF
PackagedComponent *PackagedComponent::DirectInstanceOf(AP210Object *s) {
   if (s->GetTypeID() == typeID)
      return(PackagedComponent *)s;
   return 0;
   }

PackagedComponent *PackagedComponent::InstanceOf(AP210Object *s) {
   if (s->DynamicType(typeID))
      return(PackagedComponent *)s;
   return 0;
   }
#endif
// These are two tighly coupled functions.
// The intent is that the caller will 
//    First call RenderCaps,
//    then change the color, and
//    then call RenderSides.
//#define VERBOSE
//#define VERBOSEMATRIX
void PackagedComponent::RenderCaps() {
   // save the current transformation matrix
   glPushMatrix();
   
   applyTranslationMatrix();
   PackageRef->RenderCaps();
   }
void PackagedComponent::RenderSides() {
   PackageRef->RenderSides();
   // restore the transformation matrix
   glPopMatrix();
   }

void PackagedComponent::OutputGLError(char * label) {
	GLenum errorno = glGetError() ;

	if (errorno != GL_NO_ERROR) {
		TRACE("PackagedComponent: %s had error: #(%d) %s\r\n", label, errorno, gluErrorString(errorno)) ;
      }
   }

int PackagedComponent::getReDrawStatus() {
   return PackageRef->getReDrawStatus();
   }

void PackagedComponent::setReDrawStatus(int status) {
   PackageRef->setReDrawStatus(status);
   }

GLuint PackagedComponent::getCapDisplayList() {
   return PackageRef->getCapDisplayList();
   }

GLuint PackagedComponent::getSideDisplayList() {
   return PackageRef->getSideDisplayList();
   }

void PackagedComponent::ReDraw(double Z, double Base) {
   PackageRef->ReDraw();
   }

