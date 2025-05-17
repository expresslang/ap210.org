// Source for AP210 application object
//     geometrically_bounded_2d_wireframe

// Precompiled include files
#include <StdAfx.h>

#include "geometrically_bounded_2d_wireframe.h"

// Classes

geometrically_bounded_2d_wireframe::geometrically_bounded_2d_wireframe() {
   initialize();
   }
geometrically_bounded_2d_wireframe::~geometrically_bounded_2d_wireframe() {
   // Free string attributes
   }
// intialize data members
void geometrically_bounded_2d_wireframe::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int geometrically_bounded_2d_wireframe::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = feature_shape_definition::DynamicType(ID);
      }
   return result;
   }
geometrically_bounded_2d_wireframe *geometrically_bounded_2d_wireframe::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<geometrically_bounded_2d_wireframe *>(s);
      }
   return NULL;
   }
geometrically_bounded_2d_wireframe *geometrically_bounded_2d_wireframe::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<geometrically_bounded_2d_wireframe *>(s);
      }
   return NULL;
   }
// construction factory
geometrically_bounded_2d_wireframe *geometrically_bounded_2d_wireframe::Construct() {
   geometrically_bounded_2d_wireframe *result = NULL;

   // create the geometrically_bounded_2d_wireframe.
   result = new geometrically_bounded_2d_wireframe();
   return result;
   }
bool geometrically_bounded_2d_wireframe::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: geometrically_bounded_2d_wireframe\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (feature_shape_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
