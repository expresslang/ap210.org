// Source for AP210 application object
//     signal

// Precompiled include files
#include <StdAfx.h>

#include "signal.h"

// Classes
#include <external_definition.h>

signal::signal() {
   initialize();
   }
signal::~signal() {
   // Free string attributes
   }
// intialize data members
void signal::initialize() {
   // Required attributes
   _signal_category = NULL;

   // Optional attributes
   }
// Runtime type identification
int signal::DynamicType(int ID) {
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
signal *signal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<signal *>(s);
      }
   return NULL;
   }
signal *signal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<signal *>(s);
      }
   return NULL;
   }
// construction factory
signal *signal::Construct() {
   signal *result = NULL;

   // create the signal.
   result = new signal();
   return result;
   }
bool signal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: signal\r\n");

   // Check for the existence of all required attributes
   if (_signal_category == NULL) {
      TRACE("ERROR: _signal_category a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
