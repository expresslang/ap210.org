// Source for AP210 application object
//     printed_connector_template_terminal_relationship

// Precompiled include files
#include <StdAfx.h>

#include "printed_connector_template_terminal_relationship.h"

// Classes
#include <printed_part_template_join_terminal.h>
#include <printed_part_template_interface_terminal.h>
#include <printed_connector_template.h>

printed_connector_template_terminal_relationship::printed_connector_template_terminal_relationship() {
   initialize();
   }
printed_connector_template_terminal_relationship::~printed_connector_template_terminal_relationship() {
   // Free string attributes
   }
// intialize data members
void printed_connector_template_terminal_relationship::initialize() {
   // Required attributes
   _join_terminal = NULL;
   _interface_terminal = NULL;
   _connector = NULL;

   // Optional attributes
   }
// Runtime type identification
int printed_connector_template_terminal_relationship::DynamicType(int ID) {
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
printed_connector_template_terminal_relationship *printed_connector_template_terminal_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_connector_template_terminal_relationship *>(s);
      }
   return NULL;
   }
printed_connector_template_terminal_relationship *printed_connector_template_terminal_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_connector_template_terminal_relationship *>(s);
      }
   return NULL;
   }
// construction factory
printed_connector_template_terminal_relationship *printed_connector_template_terminal_relationship::Construct() {
   printed_connector_template_terminal_relationship *result = NULL;

   // create the printed_connector_template_terminal_relationship.
   result = new printed_connector_template_terminal_relationship();
   return result;
   }
bool printed_connector_template_terminal_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_connector_template_terminal_relationship\r\n");

   // Check for the existence of all required attributes
   if (_join_terminal == NULL) {
      TRACE("ERROR: _join_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_interface_terminal == NULL) {
      TRACE("ERROR: _interface_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_connector == NULL) {
      TRACE("ERROR: _connector a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
