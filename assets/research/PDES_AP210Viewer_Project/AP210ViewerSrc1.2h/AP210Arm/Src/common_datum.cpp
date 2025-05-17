// Source for AP210 application object
//     common_datum

// Precompiled include files
#include <StdAfx.h>

#include "common_datum.h"

// Classes

common_datum::common_datum() {
   initialize();
   }
common_datum::~common_datum() {
   // Free string attributes
   }
// intialize data members
void common_datum::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int common_datum::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = datum::DynamicType(ID);
      }
   return result;
   }
common_datum *common_datum::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<common_datum *>(s);
      }
   return NULL;
   }
common_datum *common_datum::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<common_datum *>(s);
      }
   return NULL;
   }
// construction factory
common_datum *common_datum::Construct() {
   common_datum *result = NULL;

   // create the common_datum.
   result = new common_datum();
   return result;
   }
bool common_datum::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: common_datum\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (datum::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
