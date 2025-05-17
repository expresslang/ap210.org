// Source for AP210 application object
//     plus_minus_tolerance_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "plus_minus_tolerance_characteristic.h"

// Classes

plus_minus_tolerance_characteristic::plus_minus_tolerance_characteristic() {
   initialize();
   }
plus_minus_tolerance_characteristic::~plus_minus_tolerance_characteristic() {
   // Free string attributes
   }
// intialize data members
void plus_minus_tolerance_characteristic::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int plus_minus_tolerance_characteristic::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = tolerance_characteristic::DynamicType(ID);
      }
   return result;
   }
plus_minus_tolerance_characteristic *plus_minus_tolerance_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<plus_minus_tolerance_characteristic *>(s);
      }
   return NULL;
   }
plus_minus_tolerance_characteristic *plus_minus_tolerance_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<plus_minus_tolerance_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
plus_minus_tolerance_characteristic *plus_minus_tolerance_characteristic::Construct() {
   plus_minus_tolerance_characteristic *result = NULL;

   // create the plus_minus_tolerance_characteristic.
   result = new plus_minus_tolerance_characteristic();
   return result;
   }
bool plus_minus_tolerance_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: plus_minus_tolerance_characteristic\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (tolerance_characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
