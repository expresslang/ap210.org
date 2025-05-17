// Source for AP210 application object
//     SetOfinterface_component

// Precompiled include files
#include <StdAfx.h>

#include "SetOfinterface_component.h"

// Classes
#include <interface_component.h>

SetOfinterface_component::SetOfinterface_component() {
   initialize();
   }
SetOfinterface_component::~SetOfinterface_component() {
   // Free string attributes
   }
// intialize data members
void SetOfinterface_component::initialize() {
   // Required attributes
   _interface_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfinterface_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfinterface_component *SetOfinterface_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfinterface_component *>(s);
      }
   return NULL;
   }
SetOfinterface_component *SetOfinterface_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfinterface_component *>(s);
      }
   return NULL;
   }
// construction factory
SetOfinterface_component *SetOfinterface_component::Construct() {
   SetOfinterface_component *result = NULL;

   // create the SetOfinterface_component.
   result = new SetOfinterface_component();
   return result;
   }
bool SetOfinterface_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfinterface_component\r\n");

   // Check for the existence of all required attributes
   if (_interface_component == NULL) {
      TRACE("ERROR: _interface_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
