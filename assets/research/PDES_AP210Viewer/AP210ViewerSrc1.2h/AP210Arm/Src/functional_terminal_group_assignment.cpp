// Source for AP210 application object
//     functional_terminal_group_assignment

// Precompiled include files
#include <StdAfx.h>

#include "functional_terminal_group_assignment.h"

// Classes
#include <functional_terminal_group.h>
#include <scalar_terminal_definition.h>

functional_terminal_group_assignment::functional_terminal_group_assignment() {
   initialize();
   }
functional_terminal_group_assignment::~functional_terminal_group_assignment() {
   // Free string attributes
   }
// intialize data members
void functional_terminal_group_assignment::initialize() {
   // Required attributes
   _composed_group = NULL;
   _functional_usage_view_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_terminal_group_assignment::DynamicType(int ID) {
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
functional_terminal_group_assignment *functional_terminal_group_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_terminal_group_assignment *>(s);
      }
   return NULL;
   }
functional_terminal_group_assignment *functional_terminal_group_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_terminal_group_assignment *>(s);
      }
   return NULL;
   }
// construction factory
functional_terminal_group_assignment *functional_terminal_group_assignment::Construct() {
   functional_terminal_group_assignment *result = NULL;

   // create the functional_terminal_group_assignment.
   result = new functional_terminal_group_assignment();
   return result;
   }
bool functional_terminal_group_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_terminal_group_assignment\r\n");

   // Check for the existence of all required attributes
   if (_composed_group == NULL) {
      TRACE("ERROR: _composed_group a required attribute is NULL!\r\n");
      result = false;
      }
   if (_functional_usage_view_terminal == NULL) {
      TRACE("ERROR: _functional_usage_view_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
