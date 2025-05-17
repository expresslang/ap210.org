// Source for AP210 application object
//     edge_based_wireframe

// Precompiled include files
#include <StdAfx.h>

#include "edge_based_wireframe.h"

// Classes

edge_based_wireframe::edge_based_wireframe() {
   initialize();
   }
edge_based_wireframe::~edge_based_wireframe() {
   // Free string attributes
   }
// intialize data members
void edge_based_wireframe::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int edge_based_wireframe::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = bound_volume_shape::DynamicType(ID);
      }
   return result;
   }
edge_based_wireframe *edge_based_wireframe::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<edge_based_wireframe *>(s);
      }
   return NULL;
   }
edge_based_wireframe *edge_based_wireframe::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<edge_based_wireframe *>(s);
      }
   return NULL;
   }
// construction factory
edge_based_wireframe *edge_based_wireframe::Construct() {
   edge_based_wireframe *result = NULL;

   // create the edge_based_wireframe.
   result = new edge_based_wireframe();
   return result;
   }
bool edge_based_wireframe::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: edge_based_wireframe\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (bound_volume_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
