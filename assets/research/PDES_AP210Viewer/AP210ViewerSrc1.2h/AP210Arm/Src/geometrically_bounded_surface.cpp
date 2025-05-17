// Source for AP210 application object
//     geometrically_bounded_surface

// Precompiled include files
#include <StdAfx.h>

#include "geometrically_bounded_surface.h"

// Classes

geometrically_bounded_surface::geometrically_bounded_surface() {
   initialize();
   }
geometrically_bounded_surface::~geometrically_bounded_surface() {
   // Free string attributes
   }
// intialize data members
void geometrically_bounded_surface::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int geometrically_bounded_surface::DynamicType(int ID) {
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
geometrically_bounded_surface *geometrically_bounded_surface::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<geometrically_bounded_surface *>(s);
      }
   return NULL;
   }
geometrically_bounded_surface *geometrically_bounded_surface::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<geometrically_bounded_surface *>(s);
      }
   return NULL;
   }
// construction factory
geometrically_bounded_surface *geometrically_bounded_surface::Construct() {
   geometrically_bounded_surface *result = NULL;

   // create the geometrically_bounded_surface.
   result = new geometrically_bounded_surface();
   return result;
   }
bool geometrically_bounded_surface::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: geometrically_bounded_surface\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (bound_volume_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
