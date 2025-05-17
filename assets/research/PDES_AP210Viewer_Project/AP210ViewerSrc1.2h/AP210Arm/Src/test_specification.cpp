// Source for AP210 application object
//     test_specification

// Precompiled include files
#include <StdAfx.h>

#include "test_specification.h"

// Classes

test_specification::test_specification() {
   initialize();
   }
test_specification::~test_specification() {
   // Free string attributes
   }
// intialize data members
void test_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int test_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_specification::DynamicType(ID);
      }
   return result;
   }
test_specification *test_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<test_specification *>(s);
      }
   return NULL;
   }
test_specification *test_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<test_specification *>(s);
      }
   return NULL;
   }
// construction factory
test_specification *test_specification::Construct() {
   test_specification *result = NULL;

   // create the test_specification.
   result = new test_specification();
   return result;
   }
bool test_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: test_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_specification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
