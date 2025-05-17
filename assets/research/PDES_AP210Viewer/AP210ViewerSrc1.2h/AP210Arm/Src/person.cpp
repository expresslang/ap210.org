// Source for AP210 application object
//     person

// Precompiled include files
#include <StdAfx.h>

#include "person.h"

// Classes

person::person() {
   initialize();
   }
person::~person() {
   // Free string attributes
   if (_identifier != NULL) {
      free(_identifier);
     }
   if (_Address != NULL) {
      free(_Address);
     }
   }
// intialize data members
void person::initialize() {
   // Required attributes
   _identifier = NULL;

   // Optional attributes
   _Address = NULL;
   }
// Runtime type identification
int person::DynamicType(int ID) {
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
person *person::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<person *>(s);
      }
   return NULL;
   }
person *person::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<person *>(s);
      }
   return NULL;
   }
// construction factory
person *person::Construct() {
   person *result = NULL;

   // create the person.
   result = new person();
   return result;
   }
bool person::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: person\r\n");

   // Check for the existence of all required attributes
   if (_identifier == NULL) {
      TRACE("ERROR: _identifier a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
