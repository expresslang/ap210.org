// Source for AP210 application object
//     datum_difference_based_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "datum_difference_based_characteristic.h"

// Classes
#include <datum_difference.h>

datum_difference_based_characteristic::datum_difference_based_characteristic() {
   initialize();
   }
datum_difference_based_characteristic::~datum_difference_based_characteristic() {
   // Free string attributes
   }
// intialize data members
void datum_difference_based_characteristic::initialize() {
   // Required attributes
   _of_datum_difference = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_difference_based_characteristic::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = characteristic::DynamicType(ID);
      }
   return result;
   }
datum_difference_based_characteristic *datum_difference_based_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_difference_based_characteristic *>(s);
      }
   return NULL;
   }
datum_difference_based_characteristic *datum_difference_based_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_difference_based_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
datum_difference_based_characteristic *datum_difference_based_characteristic::Construct() {
   datum_difference_based_characteristic *result = NULL;

   // create the datum_difference_based_characteristic.
   result = new datum_difference_based_characteristic();
   return result;
   }
bool datum_difference_based_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_difference_based_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_of_datum_difference == NULL) {
      TRACE("ERROR: _of_datum_difference a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
