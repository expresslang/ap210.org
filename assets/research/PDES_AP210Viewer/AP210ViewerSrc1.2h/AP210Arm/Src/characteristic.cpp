// Source for AP210 application object
//     characteristic

// Precompiled include files
#include <StdAfx.h>

#include "characteristic.h"

// Classes

characteristic::characteristic() {
   initialize();
   }
characteristic::~characteristic() {
   // Free string attributes
   if (_type_name != NULL) {
      free(_type_name);
     }
   }
// intialize data members
void characteristic::initialize() {
   // Required attributes
   _type_name = NULL;

   // Optional attributes
   }
// Runtime type identification
int characteristic::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
characteristic *characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<characteristic *>(s);
      }
   return NULL;
   }
characteristic *characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<characteristic *>(s);
      }
   return NULL;
   }
// construction factory
characteristic *characteristic::Construct() {
   characteristic *result = NULL;

   // create the characteristic.
   result = new characteristic();
   return result;
   }
bool characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: characteristic\r\n");

   // Check for the existence of all required attributes
   if (_type_name == NULL) {
      TRACE("ERROR: _type_name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_document == NULL) {
      TRACE("ERROR: _reference_document a required attribute is NULL!\r\n");
      result = false;
      }
   if (_property_value == NULL) {
      TRACE("ERROR: _property_value a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
