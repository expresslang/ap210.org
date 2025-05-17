// Source for AP210 application object
//     functional_unit_usage_view_terminal_definition

// Precompiled include files
#include <StdAfx.h>

#include "functional_unit_usage_view_terminal_definition.h"

// Classes
#include <functional_unit_usage_view.h>

functional_unit_usage_view_terminal_definition::functional_unit_usage_view_terminal_definition() {
   initialize();
   }
functional_unit_usage_view_terminal_definition::~functional_unit_usage_view_terminal_definition() {
   // Free string attributes
   if (_signal_name != NULL) {
      free(_signal_name);
     }
   }
// intialize data members
void functional_unit_usage_view_terminal_definition::initialize() {
   // Required attributes
   _associated_functional_unit_definition = NULL;
   _signal_name = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_unit_usage_view_terminal_definition::DynamicType(int ID) {
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
functional_unit_usage_view_terminal_definition *functional_unit_usage_view_terminal_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_unit_usage_view_terminal_definition *>(s);
      }
   return NULL;
   }
functional_unit_usage_view_terminal_definition *functional_unit_usage_view_terminal_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_unit_usage_view_terminal_definition *>(s);
      }
   return NULL;
   }
// construction factory
functional_unit_usage_view_terminal_definition *functional_unit_usage_view_terminal_definition::Construct() {
   functional_unit_usage_view_terminal_definition *result = NULL;

   // create the functional_unit_usage_view_terminal_definition.
   result = new functional_unit_usage_view_terminal_definition();
   return result;
   }
bool functional_unit_usage_view_terminal_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_unit_usage_view_terminal_definition\r\n");

   // Check for the existence of all required attributes
   if (_associated_functional_unit_definition == NULL) {
      TRACE("ERROR: _associated_functional_unit_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_signal_name == NULL) {
      TRACE("ERROR: _signal_name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
