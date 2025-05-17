// Source for AP210 application object
//     tangent_shape_element

// Precompiled include files
#include <StdAfx.h>

#include "tangent_shape_element.h"

// Classes

tangent_shape_element::tangent_shape_element() {
   initialize();
   }
tangent_shape_element::~tangent_shape_element() {
   // Free string attributes
   }
// intialize data members
void tangent_shape_element::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int tangent_shape_element::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = derived_shape_element::DynamicType(ID);
      }
   return result;
   }
tangent_shape_element *tangent_shape_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tangent_shape_element *>(s);
      }
   return NULL;
   }
tangent_shape_element *tangent_shape_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tangent_shape_element *>(s);
      }
   return NULL;
   }
// construction factory
tangent_shape_element *tangent_shape_element::Construct() {
   tangent_shape_element *result = NULL;

   // create the tangent_shape_element.
   result = new tangent_shape_element();
   return result;
   }
bool tangent_shape_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tangent_shape_element\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (derived_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
