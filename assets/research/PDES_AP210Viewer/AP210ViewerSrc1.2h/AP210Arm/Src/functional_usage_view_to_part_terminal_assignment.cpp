// Source for AP210 application object
//     functional_usage_view_to_part_terminal_assignment

// Precompiled include files
#include <StdAfx.h>

#include "functional_usage_view_to_part_terminal_assignment.h"

// Classes
#include <part_terminal.h>
#include <scalar_terminal_definition.h>

functional_usage_view_to_part_terminal_assignment::functional_usage_view_to_part_terminal_assignment() {
   initialize();
   }
functional_usage_view_to_part_terminal_assignment::~functional_usage_view_to_part_terminal_assignment() {
   // Free string attributes
   }
// intialize data members
void functional_usage_view_to_part_terminal_assignment::initialize() {
   // Required attributes
   _physical_usage_view_terminal = NULL;
   _functional_usage_view_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_usage_view_to_part_terminal_assignment::DynamicType(int ID) {
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
functional_usage_view_to_part_terminal_assignment *functional_usage_view_to_part_terminal_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_usage_view_to_part_terminal_assignment *>(s);
      }
   return NULL;
   }
functional_usage_view_to_part_terminal_assignment *functional_usage_view_to_part_terminal_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_usage_view_to_part_terminal_assignment *>(s);
      }
   return NULL;
   }
// construction factory
functional_usage_view_to_part_terminal_assignment *functional_usage_view_to_part_terminal_assignment::Construct() {
   functional_usage_view_to_part_terminal_assignment *result = NULL;

   // create the functional_usage_view_to_part_terminal_assignment.
   result = new functional_usage_view_to_part_terminal_assignment();
   return result;
   }
bool functional_usage_view_to_part_terminal_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_usage_view_to_part_terminal_assignment\r\n");

   // Check for the existence of all required attributes
   if (_physical_usage_view_terminal == NULL) {
      TRACE("ERROR: _physical_usage_view_terminal a required attribute is NULL!\r\n");
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
