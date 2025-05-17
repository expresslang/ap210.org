// Source for AP210 application object
//     SetOfinterface_mounted_join

// Precompiled include files
#include <StdAfx.h>

#include "SetOfinterface_mounted_join.h"

// Classes
#include <interface_mounted_join.h>

SetOfinterface_mounted_join::SetOfinterface_mounted_join() {
   initialize();
   }
SetOfinterface_mounted_join::~SetOfinterface_mounted_join() {
   // Free string attributes
   }
// intialize data members
void SetOfinterface_mounted_join::initialize() {
   // Required attributes
   _interface_mounted_join = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfinterface_mounted_join::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfinterface_mounted_join *SetOfinterface_mounted_join::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfinterface_mounted_join *>(s);
      }
   return NULL;
   }
SetOfinterface_mounted_join *SetOfinterface_mounted_join::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfinterface_mounted_join *>(s);
      }
   return NULL;
   }
// construction factory
SetOfinterface_mounted_join *SetOfinterface_mounted_join::Construct() {
   SetOfinterface_mounted_join *result = NULL;

   // create the SetOfinterface_mounted_join.
   result = new SetOfinterface_mounted_join();
   return result;
   }
bool SetOfinterface_mounted_join::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfinterface_mounted_join\r\n");

   // Check for the existence of all required attributes
   if (_interface_mounted_join == NULL) {
      TRACE("ERROR: _interface_mounted_join a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
