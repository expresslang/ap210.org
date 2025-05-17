// Source for AP210 application object
//     tangent_plane

// Precompiled include files
#include <StdAfx.h>

#include "tangent_plane.h"

// Classes

tangent_plane::tangent_plane() {
   initialize();
   }
tangent_plane::~tangent_plane() {
   // Free string attributes
   }
// intialize data members
void tangent_plane::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int tangent_plane::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = tangent_shape_element::DynamicType(ID);
      }
   return result;
   }
tangent_plane *tangent_plane::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tangent_plane *>(s);
      }
   return NULL;
   }
tangent_plane *tangent_plane::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tangent_plane *>(s);
      }
   return NULL;
   }
// construction factory
tangent_plane *tangent_plane::Construct() {
   tangent_plane *result = NULL;

   // create the tangent_plane.
   result = new tangent_plane();
   return result;
   }
bool tangent_plane::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tangent_plane\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (tangent_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
