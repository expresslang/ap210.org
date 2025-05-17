// Source for AP210 application object
//     composite_unit_shape_element

// Precompiled include files
#include <StdAfx.h>

#include "composite_unit_shape_element.h"

// Classes

composite_unit_shape_element::composite_unit_shape_element() {
   initialize();
   }
composite_unit_shape_element::~composite_unit_shape_element() {
   // Free string attributes
   }
// intialize data members
void composite_unit_shape_element::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int composite_unit_shape_element::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = composite_shape_element::DynamicType(ID);
      }
   return result;
   }
composite_unit_shape_element *composite_unit_shape_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<composite_unit_shape_element *>(s);
      }
   return NULL;
   }
composite_unit_shape_element *composite_unit_shape_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<composite_unit_shape_element *>(s);
      }
   return NULL;
   }
// construction factory
composite_unit_shape_element *composite_unit_shape_element::Construct() {
   composite_unit_shape_element *result = NULL;

   // create the composite_unit_shape_element.
   result = new composite_unit_shape_element();
   return result;
   }
bool composite_unit_shape_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: composite_unit_shape_element\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (composite_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
