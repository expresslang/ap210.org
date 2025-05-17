// Source for AP210 application object
//     component_terminal_to_interconnect_module_terminal_assignment

// Precompiled include files
#include <StdAfx.h>

#include "component_terminal_to_interconnect_module_terminal_assignment.h"

// Classes
#include <interconnect_module_terminal.h>

component_terminal_to_interconnect_module_terminal_assignment::component_terminal_to_interconnect_module_terminal_assignment() {
   initialize();
   }
component_terminal_to_interconnect_module_terminal_assignment::~component_terminal_to_interconnect_module_terminal_assignment() {
   // Free string attributes
   }
// intialize data members
void component_terminal_to_interconnect_module_terminal_assignment::initialize() {
   // Required attributes
   _usage_view_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_terminal_to_interconnect_module_terminal_assignment::DynamicType(int ID) {
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
component_terminal_to_interconnect_module_terminal_assignment *component_terminal_to_interconnect_module_terminal_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_terminal_to_interconnect_module_terminal_assignment *>(s);
      }
   return NULL;
   }
component_terminal_to_interconnect_module_terminal_assignment *component_terminal_to_interconnect_module_terminal_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_terminal_to_interconnect_module_terminal_assignment *>(s);
      }
   return NULL;
   }
// construction factory
component_terminal_to_interconnect_module_terminal_assignment *component_terminal_to_interconnect_module_terminal_assignment::Construct() {
   component_terminal_to_interconnect_module_terminal_assignment *result = NULL;

   // create the component_terminal_to_interconnect_module_terminal_assignment.
   result = new component_terminal_to_interconnect_module_terminal_assignment();
   return result;
   }
bool component_terminal_to_interconnect_module_terminal_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_terminal_to_interconnect_module_terminal_assignment\r\n");

   // Check for the existence of all required attributes
   if (_usage_view_terminal == NULL) {
      TRACE("ERROR: _usage_view_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_terminal == NULL) {
      TRACE("ERROR: _assigned_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
