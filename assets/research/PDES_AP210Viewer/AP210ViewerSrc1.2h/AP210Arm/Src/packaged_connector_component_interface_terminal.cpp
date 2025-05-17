// Source for AP210 application object
//     packaged_connector_component_interface_terminal

// Precompiled include files
#include <StdAfx.h>

#include "packaged_connector_component_interface_terminal.h"

// Classes

packaged_connector_component_interface_terminal::packaged_connector_component_interface_terminal() {
   initialize();
   }
packaged_connector_component_interface_terminal::~packaged_connector_component_interface_terminal() {
   // Free string attributes
   }
// intialize data members
void packaged_connector_component_interface_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int packaged_connector_component_interface_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = component_interface_terminal::DynamicType(ID);
      }
   return result;
   }
packaged_connector_component_interface_terminal *packaged_connector_component_interface_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<packaged_connector_component_interface_terminal *>(s);
      }
   return NULL;
   }
packaged_connector_component_interface_terminal *packaged_connector_component_interface_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<packaged_connector_component_interface_terminal *>(s);
      }
   return NULL;
   }
// construction factory
packaged_connector_component_interface_terminal *packaged_connector_component_interface_terminal::Construct() {
   packaged_connector_component_interface_terminal *result = NULL;

   // create the packaged_connector_component_interface_terminal.
   result = new packaged_connector_component_interface_terminal();
   return result;
   }
bool packaged_connector_component_interface_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: packaged_connector_component_interface_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_interface_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
