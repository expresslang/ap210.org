// Source for AP210 application object
//     test_select_product

// Precompiled include files
#include <StdAfx.h>

#include "test_select_product.h"

// Classes

test_select_product::test_select_product() {
   initialize();
   }
test_select_product::~test_select_product() {
   // Free string attributes
   }
// intialize data members
void test_select_product::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int test_select_product::DynamicType(int ID) {
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
test_select_product *test_select_product::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<test_select_product *>(s);
      }
   return NULL;
   }
test_select_product *test_select_product::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<test_select_product *>(s);
      }
   return NULL;
   }
// construction factory
test_select_product *test_select_product::Construct() {
   test_select_product *result = NULL;

   // create the test_select_product.
   result = new test_select_product();
   return result;
   }
bool test_select_product::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: test_select_product\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (alternate_select_product::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
