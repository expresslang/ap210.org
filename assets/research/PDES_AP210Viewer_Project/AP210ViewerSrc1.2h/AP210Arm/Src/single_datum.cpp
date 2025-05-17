// Source for AP210 application object
//     single_datum

// Precompiled include files
#include <StdAfx.h>

#include "single_datum.h"

// Classes

single_datum::single_datum() {
   initialize();
   }
single_datum::~single_datum() {
   // Free string attributes
   }
// intialize data members
void single_datum::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int single_datum::DynamicType(int ID) {
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
single_datum *single_datum::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<single_datum *>(s);
      }
   return NULL;
   }
single_datum *single_datum::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<single_datum *>(s);
      }
   return NULL;
   }
// construction factory
single_datum *single_datum::Construct() {
   single_datum *result = NULL;

   // create the single_datum.
   result = new single_datum();
   return result;
   }
bool single_datum::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: single_datum\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (datum::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
