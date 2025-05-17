// Source for AP210 application object
//     SetOfinterconnect_module

// Precompiled include files
#include <StdAfx.h>

#include "SetOfinterconnect_module.h"

// Classes
#include <interconnect_module.h>

SetOfinterconnect_module::SetOfinterconnect_module() {
   initialize();
   }
SetOfinterconnect_module::~SetOfinterconnect_module() {
   // Free string attributes
   }
// intialize data members
void SetOfinterconnect_module::initialize() {
   // Required attributes
   _interconnect_module = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfinterconnect_module::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfinterconnect_module *SetOfinterconnect_module::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfinterconnect_module *>(s);
      }
   return NULL;
   }
SetOfinterconnect_module *SetOfinterconnect_module::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfinterconnect_module *>(s);
      }
   return NULL;
   }
// construction factory
SetOfinterconnect_module *SetOfinterconnect_module::Construct() {
   SetOfinterconnect_module *result = NULL;

   // create the SetOfinterconnect_module.
   result = new SetOfinterconnect_module();
   return result;
   }
bool SetOfinterconnect_module::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfinterconnect_module\r\n");

   // Check for the existence of all required attributes
   if (_interconnect_module == NULL) {
      TRACE("ERROR: _interconnect_module a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
