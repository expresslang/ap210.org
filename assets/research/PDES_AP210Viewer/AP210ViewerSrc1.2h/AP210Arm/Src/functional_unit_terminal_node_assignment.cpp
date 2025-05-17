// Source for AP210 application object
//     functional_unit_terminal_node_assignment

// Precompiled include files
#include <StdAfx.h>

#include "functional_unit_terminal_node_assignment.h"

// Classes
#include <functional_unit_network_node_definition.h>
#include <functional_unit_terminal.h>

functional_unit_terminal_node_assignment::functional_unit_terminal_node_assignment() {
   initialize();
   }
functional_unit_terminal_node_assignment::~functional_unit_terminal_node_assignment() {
   // Free string attributes
   }
// intialize data members
void functional_unit_terminal_node_assignment::initialize() {
   // Required attributes
   _composed_node = NULL;
   _connected_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_unit_terminal_node_assignment::DynamicType(int ID) {
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
functional_unit_terminal_node_assignment *functional_unit_terminal_node_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_unit_terminal_node_assignment *>(s);
      }
   return NULL;
   }
functional_unit_terminal_node_assignment *functional_unit_terminal_node_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_unit_terminal_node_assignment *>(s);
      }
   return NULL;
   }
// construction factory
functional_unit_terminal_node_assignment *functional_unit_terminal_node_assignment::Construct() {
   functional_unit_terminal_node_assignment *result = NULL;

   // create the functional_unit_terminal_node_assignment.
   result = new functional_unit_terminal_node_assignment();
   return result;
   }
bool functional_unit_terminal_node_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_unit_terminal_node_assignment\r\n");

   // Check for the existence of all required attributes
   if (_composed_node == NULL) {
      TRACE("ERROR: _composed_node a required attribute is NULL!\r\n");
      result = false;
      }
   if (_connected_terminal == NULL) {
      TRACE("ERROR: _connected_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
