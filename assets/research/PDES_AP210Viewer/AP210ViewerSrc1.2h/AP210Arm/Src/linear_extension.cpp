// Source for AP210 application object
//     linear_extension

// Precompiled include files
#include <StdAfx.h>

#include "linear_extension.h"

// Classes

linear_extension::linear_extension() {
   initialize();
   }
linear_extension::~linear_extension() {
   // Free string attributes
   }
// intialize data members
void linear_extension::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int linear_extension::DynamicType(int ID) {
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
linear_extension *linear_extension::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<linear_extension *>(s);
      }
   return NULL;
   }
linear_extension *linear_extension::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<linear_extension *>(s);
      }
   return NULL;
   }
// construction factory
linear_extension *linear_extension::Construct() {
   linear_extension *result = NULL;

   // create the linear_extension.
   result = new linear_extension();
   return result;
   }
bool linear_extension::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: linear_extension\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (derived_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
