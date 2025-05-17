// Source for AP210 application object
//     transmission_line_functional_unit_terminal_allocation

// Precompiled include files
#include <StdAfx.h>

#include "transmission_line_functional_unit_terminal_allocation.h"

// Classes
#include <printed_component_join_terminal.h>
#include <functional_unit_terminal.h>
#include <transmission_line_functional_unit_to_routed_printed_component_allocation.h>

transmission_line_functional_unit_terminal_allocation::transmission_line_functional_unit_terminal_allocation() {
   initialize();
   }
transmission_line_functional_unit_terminal_allocation::~transmission_line_functional_unit_terminal_allocation() {
   // Free string attributes
   }
// intialize data members
void transmission_line_functional_unit_terminal_allocation::initialize() {
   // Required attributes
   _implementation = NULL;
   _transmission_line_functional_unit_terminal = NULL;
   _functional_unit_design_path = NULL;

   // Optional attributes
   }
// Runtime type identification
int transmission_line_functional_unit_terminal_allocation::DynamicType(int ID) {
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
transmission_line_functional_unit_terminal_allocation *transmission_line_functional_unit_terminal_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<transmission_line_functional_unit_terminal_allocation *>(s);
      }
   return NULL;
   }
transmission_line_functional_unit_terminal_allocation *transmission_line_functional_unit_terminal_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<transmission_line_functional_unit_terminal_allocation *>(s);
      }
   return NULL;
   }
// construction factory
transmission_line_functional_unit_terminal_allocation *transmission_line_functional_unit_terminal_allocation::Construct() {
   transmission_line_functional_unit_terminal_allocation *result = NULL;

   // create the transmission_line_functional_unit_terminal_allocation.
   result = new transmission_line_functional_unit_terminal_allocation();
   return result;
   }
bool transmission_line_functional_unit_terminal_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: transmission_line_functional_unit_terminal_allocation\r\n");

   // Check for the existence of all required attributes
   if (_implementation == NULL) {
      TRACE("ERROR: _implementation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_transmission_line_functional_unit_terminal == NULL) {
      TRACE("ERROR: _transmission_line_functional_unit_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_functional_unit_design_path == NULL) {
      TRACE("ERROR: _functional_unit_design_path a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
