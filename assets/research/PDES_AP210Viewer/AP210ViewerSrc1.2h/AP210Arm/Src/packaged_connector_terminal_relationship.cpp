// Source for AP210 application object
//     packaged_connector_terminal_relationship

// Precompiled include files
#include <StdAfx.h>

#include "packaged_connector_terminal_relationship.h"

// Classes
#include <packaged_connector.h>
#include <packaged_part_join_terminal.h>
#include <packaged_part_interface_terminal.h>

packaged_connector_terminal_relationship::packaged_connector_terminal_relationship() {
   initialize();
   }
packaged_connector_terminal_relationship::~packaged_connector_terminal_relationship() {
   // Free string attributes
   }
// intialize data members
void packaged_connector_terminal_relationship::initialize() {
   // Required attributes
   _connector = NULL;
   _join_terminal = NULL;
   _interface_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int packaged_connector_terminal_relationship::DynamicType(int ID) {
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
packaged_connector_terminal_relationship *packaged_connector_terminal_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<packaged_connector_terminal_relationship *>(s);
      }
   return NULL;
   }
packaged_connector_terminal_relationship *packaged_connector_terminal_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<packaged_connector_terminal_relationship *>(s);
      }
   return NULL;
   }
// construction factory
packaged_connector_terminal_relationship *packaged_connector_terminal_relationship::Construct() {
   packaged_connector_terminal_relationship *result = NULL;

   // create the packaged_connector_terminal_relationship.
   result = new packaged_connector_terminal_relationship();
   return result;
   }
bool packaged_connector_terminal_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: packaged_connector_terminal_relationship\r\n");

   // Check for the existence of all required attributes
   if (_connector == NULL) {
      TRACE("ERROR: _connector a required attribute is NULL!\r\n");
      result = false;
      }
   if (_join_terminal == NULL) {
      TRACE("ERROR: _join_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_interface_terminal == NULL) {
      TRACE("ERROR: _interface_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
