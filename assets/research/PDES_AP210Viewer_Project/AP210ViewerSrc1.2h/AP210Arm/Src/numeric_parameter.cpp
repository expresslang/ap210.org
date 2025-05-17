// Source for AP210 application object
//     numeric_parameter

// Precompiled include files
#include <StdAfx.h>

#include "numeric_parameter.h"

// Classes

numeric_parameter::numeric_parameter() {
   initialize();
   }
numeric_parameter::~numeric_parameter() {
   // Free string attributes
   }
// intialize data members
void numeric_parameter::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int numeric_parameter::DynamicType(int ID) {
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
numeric_parameter *numeric_parameter::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<numeric_parameter *>(s);
      }
   return NULL;
   }
numeric_parameter *numeric_parameter::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<numeric_parameter *>(s);
      }
   return NULL;
   }
// construction factory
numeric_parameter *numeric_parameter::Construct() {
   numeric_parameter *result = NULL;

   // create the numeric_parameter.
   result = new numeric_parameter();
   return result;
   }
bool numeric_parameter::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: numeric_parameter\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
