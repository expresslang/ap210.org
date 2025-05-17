// Source for AP210 application object
//     derived_shape_element

// Precompiled include files
#include <StdAfx.h>

#include "derived_shape_element.h"

// Classes

derived_shape_element::derived_shape_element() {
   initialize();
   }
derived_shape_element::~derived_shape_element() {
   // Free string attributes
   }
// intialize data members
void derived_shape_element::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int derived_shape_element::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = non_feature_shape_element::DynamicType(ID);
      }
   return result;
   }
derived_shape_element *derived_shape_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<derived_shape_element *>(s);
      }
   return NULL;
   }
derived_shape_element *derived_shape_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<derived_shape_element *>(s);
      }
   return NULL;
   }
// construction factory
derived_shape_element *derived_shape_element::Construct() {
   derived_shape_element *result = NULL;

   // create the derived_shape_element.
   result = new derived_shape_element();
   return result;
   }
bool derived_shape_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: derived_shape_element\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (non_feature_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
