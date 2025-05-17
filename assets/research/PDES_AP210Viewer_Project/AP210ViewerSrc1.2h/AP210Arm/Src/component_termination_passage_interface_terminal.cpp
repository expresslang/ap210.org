// Source for AP210 application object
//     component_termination_passage_interface_terminal

// Precompiled include files
#include <StdAfx.h>

#include "component_termination_passage_interface_terminal.h"

// Classes

component_termination_passage_interface_terminal::component_termination_passage_interface_terminal() {
   initialize();
   }
component_termination_passage_interface_terminal::~component_termination_passage_interface_terminal() {
   // Free string attributes
   }
// intialize data members
void component_termination_passage_interface_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int component_termination_passage_interface_terminal::DynamicType(int ID) {
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
component_termination_passage_interface_terminal *component_termination_passage_interface_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_termination_passage_interface_terminal *>(s);
      }
   return NULL;
   }
component_termination_passage_interface_terminal *component_termination_passage_interface_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_termination_passage_interface_terminal *>(s);
      }
   return NULL;
   }
// construction factory
component_termination_passage_interface_terminal *component_termination_passage_interface_terminal::Construct() {
   component_termination_passage_interface_terminal *result = NULL;

   // create the component_termination_passage_interface_terminal.
   result = new component_termination_passage_interface_terminal();
   return result;
   }
bool component_termination_passage_interface_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_termination_passage_interface_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
