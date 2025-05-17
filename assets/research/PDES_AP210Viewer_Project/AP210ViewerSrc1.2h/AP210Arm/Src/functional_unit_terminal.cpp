// Source for AP210 application object
//     functional_unit_terminal

// Precompiled include files
#include <StdAfx.h>

#include "functional_unit_terminal.h"

// Classes
#include <functional_unit.h>
#include <functional_unit_usage_view_terminal_definition.h>

functional_unit_terminal::functional_unit_terminal() {
   initialize();
   }
functional_unit_terminal::~functional_unit_terminal() {
   // Free string attributes
   }
// intialize data members
void functional_unit_terminal::initialize() {
   // Required attributes
   _accessed_functional_unit = NULL;
   _definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_unit_terminal::DynamicType(int ID) {
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
functional_unit_terminal *functional_unit_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_unit_terminal *>(s);
      }
   return NULL;
   }
functional_unit_terminal *functional_unit_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_unit_terminal *>(s);
      }
   return NULL;
   }
// construction factory
functional_unit_terminal *functional_unit_terminal::Construct() {
   functional_unit_terminal *result = NULL;

   // create the functional_unit_terminal.
   result = new functional_unit_terminal();
   return result;
   }
bool functional_unit_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_unit_terminal\r\n");

   // Check for the existence of all required attributes
   if (_accessed_functional_unit == NULL) {
      TRACE("ERROR: _accessed_functional_unit a required attribute is NULL!\r\n");
      result = false;
      }
   if (_definition == NULL) {
      TRACE("ERROR: _definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
