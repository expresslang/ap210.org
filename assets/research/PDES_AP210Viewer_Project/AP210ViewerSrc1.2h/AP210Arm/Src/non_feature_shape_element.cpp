// Source for AP210 application object
//     non_feature_shape_element

// Precompiled include files
#include <StdAfx.h>

#include "non_feature_shape_element.h"

// Classes

non_feature_shape_element::non_feature_shape_element() {
   initialize();
   }
non_feature_shape_element::~non_feature_shape_element() {
   // Free string attributes
   }
// intialize data members
void non_feature_shape_element::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int non_feature_shape_element::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = shape_element::DynamicType(ID);
      }
   return result;
   }
non_feature_shape_element *non_feature_shape_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<non_feature_shape_element *>(s);
      }
   return NULL;
   }
non_feature_shape_element *non_feature_shape_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<non_feature_shape_element *>(s);
      }
   return NULL;
   }
// construction factory
non_feature_shape_element *non_feature_shape_element::Construct() {
   non_feature_shape_element *result = NULL;

   // create the non_feature_shape_element.
   result = new non_feature_shape_element();
   return result;
   }
bool non_feature_shape_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: non_feature_shape_element\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
