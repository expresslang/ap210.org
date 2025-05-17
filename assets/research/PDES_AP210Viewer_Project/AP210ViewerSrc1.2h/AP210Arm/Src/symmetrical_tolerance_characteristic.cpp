// Source for AP210 application object
//     symmetrical_tolerance_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "symmetrical_tolerance_characteristic.h"

// Classes

symmetrical_tolerance_characteristic::symmetrical_tolerance_characteristic() {
   initialize();
   }
symmetrical_tolerance_characteristic::~symmetrical_tolerance_characteristic() {
   // Free string attributes
   }
// intialize data members
void symmetrical_tolerance_characteristic::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int symmetrical_tolerance_characteristic::DynamicType(int ID) {
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
symmetrical_tolerance_characteristic *symmetrical_tolerance_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<symmetrical_tolerance_characteristic *>(s);
      }
   return NULL;
   }
symmetrical_tolerance_characteristic *symmetrical_tolerance_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<symmetrical_tolerance_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
symmetrical_tolerance_characteristic *symmetrical_tolerance_characteristic::Construct() {
   symmetrical_tolerance_characteristic *result = NULL;

   // create the symmetrical_tolerance_characteristic.
   result = new symmetrical_tolerance_characteristic();
   return result;
   }
bool symmetrical_tolerance_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: symmetrical_tolerance_characteristic\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (tolerance_characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
