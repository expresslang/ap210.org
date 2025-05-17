// Source for AP210 application object
//     tolerance_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_characteristic.h"

// Classes

tolerance_characteristic::tolerance_characteristic() {
   initialize();
   }
tolerance_characteristic::~tolerance_characteristic() {
   // Free string attributes
   }
// intialize data members
void tolerance_characteristic::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int tolerance_characteristic::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = coordinated_characteristic::DynamicType(ID);
      }
   return result;
   }
tolerance_characteristic *tolerance_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_characteristic *>(s);
      }
   return NULL;
   }
tolerance_characteristic *tolerance_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_characteristic *tolerance_characteristic::Construct() {
   tolerance_characteristic *result = NULL;

   // create the tolerance_characteristic.
   result = new tolerance_characteristic();
   return result;
   }
bool tolerance_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_characteristic\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (coordinated_characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
