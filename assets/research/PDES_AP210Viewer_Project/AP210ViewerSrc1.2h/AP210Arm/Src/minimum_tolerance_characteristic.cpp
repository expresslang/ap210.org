// Source for AP210 application object
//     minimum_tolerance_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "minimum_tolerance_characteristic.h"

// Classes

minimum_tolerance_characteristic::minimum_tolerance_characteristic() {
   initialize();
   }
minimum_tolerance_characteristic::~minimum_tolerance_characteristic() {
   // Free string attributes
   }
// intialize data members
void minimum_tolerance_characteristic::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int minimum_tolerance_characteristic::DynamicType(int ID) {
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
minimum_tolerance_characteristic *minimum_tolerance_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<minimum_tolerance_characteristic *>(s);
      }
   return NULL;
   }
minimum_tolerance_characteristic *minimum_tolerance_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<minimum_tolerance_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
minimum_tolerance_characteristic *minimum_tolerance_characteristic::Construct() {
   minimum_tolerance_characteristic *result = NULL;

   // create the minimum_tolerance_characteristic.
   result = new minimum_tolerance_characteristic();
   return result;
   }
bool minimum_tolerance_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: minimum_tolerance_characteristic\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (tolerance_characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
