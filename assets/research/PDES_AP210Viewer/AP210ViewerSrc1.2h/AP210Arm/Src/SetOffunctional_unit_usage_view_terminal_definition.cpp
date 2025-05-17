// Source for AP210 application object
//     SetOffunctional_unit_usage_view_terminal_definition

// Precompiled include files
#include <StdAfx.h>

#include "SetOffunctional_unit_usage_view_terminal_definition.h"

// Classes
#include <functional_unit_usage_view_terminal_definition.h>

SetOffunctional_unit_usage_view_terminal_definition::SetOffunctional_unit_usage_view_terminal_definition() {
   initialize();
   }
SetOffunctional_unit_usage_view_terminal_definition::~SetOffunctional_unit_usage_view_terminal_definition() {
   // Free string attributes
   }
// intialize data members
void SetOffunctional_unit_usage_view_terminal_definition::initialize() {
   // Required attributes
   _functional_unit_usage_view_terminal_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOffunctional_unit_usage_view_terminal_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOffunctional_unit_usage_view_terminal_definition *SetOffunctional_unit_usage_view_terminal_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOffunctional_unit_usage_view_terminal_definition *>(s);
      }
   return NULL;
   }
SetOffunctional_unit_usage_view_terminal_definition *SetOffunctional_unit_usage_view_terminal_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOffunctional_unit_usage_view_terminal_definition *>(s);
      }
   return NULL;
   }
// construction factory
SetOffunctional_unit_usage_view_terminal_definition *SetOffunctional_unit_usage_view_terminal_definition::Construct() {
   SetOffunctional_unit_usage_view_terminal_definition *result = NULL;

   // create the SetOffunctional_unit_usage_view_terminal_definition.
   result = new SetOffunctional_unit_usage_view_terminal_definition();
   return result;
   }
bool SetOffunctional_unit_usage_view_terminal_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOffunctional_unit_usage_view_terminal_definition\r\n");

   // Check for the existence of all required attributes
   if (_functional_unit_usage_view_terminal_definition == NULL) {
      TRACE("ERROR: _functional_unit_usage_view_terminal_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
