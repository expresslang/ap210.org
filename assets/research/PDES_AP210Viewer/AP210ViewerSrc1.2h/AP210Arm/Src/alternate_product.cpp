// Source for AP210 application object
//     alternate_product

// Precompiled include files
#include <StdAfx.h>

#include "alternate_product.h"

// Classes

alternate_product::alternate_product() {
   initialize();
   }
alternate_product::~alternate_product() {
   // Free string attributes
   }
// intialize data members
void alternate_product::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int alternate_product::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = alternate_select_product::DynamicType(ID);
      }
   return result;
   }
alternate_product *alternate_product::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<alternate_product *>(s);
      }
   return NULL;
   }
alternate_product *alternate_product::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<alternate_product *>(s);
      }
   return NULL;
   }
// construction factory
alternate_product *alternate_product::Construct() {
   alternate_product *result = NULL;

   // create the alternate_product.
   result = new alternate_product();
   return result;
   }
bool alternate_product::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: alternate_product\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (alternate_select_product::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
