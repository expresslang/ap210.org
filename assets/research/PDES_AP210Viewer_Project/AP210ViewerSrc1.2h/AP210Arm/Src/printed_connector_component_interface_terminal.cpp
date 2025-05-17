// Source for AP210 application object
//     printed_connector_component_interface_terminal

// Precompiled include files
#include <StdAfx.h>

#include "printed_connector_component_interface_terminal.h"

// Classes

printed_connector_component_interface_terminal::printed_connector_component_interface_terminal() {
   initialize();
   }
printed_connector_component_interface_terminal::~printed_connector_component_interface_terminal() {
   // Free string attributes
   }
// intialize data members
void printed_connector_component_interface_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int printed_connector_component_interface_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = component_feature::DynamicType(ID);
      }
   return result;
   }
printed_connector_component_interface_terminal *printed_connector_component_interface_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_connector_component_interface_terminal *>(s);
      }
   return NULL;
   }
printed_connector_component_interface_terminal *printed_connector_component_interface_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_connector_component_interface_terminal *>(s);
      }
   return NULL;
   }
// construction factory
printed_connector_component_interface_terminal *printed_connector_component_interface_terminal::Construct() {
   printed_connector_component_interface_terminal *result = NULL;

   // create the printed_connector_component_interface_terminal.
   result = new printed_connector_component_interface_terminal();
   return result;
   }
bool printed_connector_component_interface_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_connector_component_interface_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
