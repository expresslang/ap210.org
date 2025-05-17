// Source for AP210 application object
//     apex

// Precompiled include files
#include <StdAfx.h>

#include "apex.h"

// Classes

apex::apex() {
   initialize();
   }
apex::~apex() {
   // Free string attributes
   }
// intialize data members
void apex::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int apex::DynamicType(int ID) {
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
apex *apex::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<apex *>(s);
      }
   return NULL;
   }
apex *apex::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<apex *>(s);
      }
   return NULL;
   }
// construction factory
apex *apex::Construct() {
   apex *result = NULL;

   // create the apex.
   result = new apex();
   return result;
   }
bool apex::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: apex\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (derived_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
