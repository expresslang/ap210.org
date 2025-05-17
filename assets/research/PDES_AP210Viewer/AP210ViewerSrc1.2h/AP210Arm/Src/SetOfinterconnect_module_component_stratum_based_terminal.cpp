// Source for AP210 application object
//     SetOfinterconnect_module_component_stratum_based_terminal

// Precompiled include files
#include <StdAfx.h>

#include "SetOfinterconnect_module_component_stratum_based_terminal.h"

// Classes
#include <interconnect_module_component_stratum_based_terminal.h>

SetOfinterconnect_module_component_stratum_based_terminal::SetOfinterconnect_module_component_stratum_based_terminal() {
   initialize();
   }
SetOfinterconnect_module_component_stratum_based_terminal::~SetOfinterconnect_module_component_stratum_based_terminal() {
   // Free string attributes
   }
// intialize data members
void SetOfinterconnect_module_component_stratum_based_terminal::initialize() {
   // Required attributes
   _interconnect_module_component_stratum_based_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfinterconnect_module_component_stratum_based_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfinterconnect_module_component_stratum_based_terminal *SetOfinterconnect_module_component_stratum_based_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfinterconnect_module_component_stratum_based_terminal *>(s);
      }
   return NULL;
   }
SetOfinterconnect_module_component_stratum_based_terminal *SetOfinterconnect_module_component_stratum_based_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfinterconnect_module_component_stratum_based_terminal *>(s);
      }
   return NULL;
   }
// construction factory
SetOfinterconnect_module_component_stratum_based_terminal *SetOfinterconnect_module_component_stratum_based_terminal::Construct() {
   SetOfinterconnect_module_component_stratum_based_terminal *result = NULL;

   // create the SetOfinterconnect_module_component_stratum_based_terminal.
   result = new SetOfinterconnect_module_component_stratum_based_terminal();
   return result;
   }
bool SetOfinterconnect_module_component_stratum_based_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfinterconnect_module_component_stratum_based_terminal\r\n");

   // Check for the existence of all required attributes
   if (_interconnect_module_component_stratum_based_terminal == NULL) {
      TRACE("ERROR: _interconnect_module_component_stratum_based_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
