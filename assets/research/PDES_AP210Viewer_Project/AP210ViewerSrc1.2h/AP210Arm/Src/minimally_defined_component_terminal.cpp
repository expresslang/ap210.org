// Source for AP210 application object
//     minimally_defined_component_terminal

// Precompiled include files
#include <StdAfx.h>

#include "minimally_defined_component_terminal.h"

// Classes

minimally_defined_component_terminal::minimally_defined_component_terminal() {
   initialize();
   }
minimally_defined_component_terminal::~minimally_defined_component_terminal() {
   // Free string attributes
   }
// intialize data members
void minimally_defined_component_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int minimally_defined_component_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = component_terminal::DynamicType(ID);
      }
   return result;
   }
minimally_defined_component_terminal *minimally_defined_component_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<minimally_defined_component_terminal *>(s);
      }
   return NULL;
   }
minimally_defined_component_terminal *minimally_defined_component_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<minimally_defined_component_terminal *>(s);
      }
   return NULL;
   }
// construction factory
minimally_defined_component_terminal *minimally_defined_component_terminal::Construct() {
   minimally_defined_component_terminal *result = NULL;

   // create the minimally_defined_component_terminal.
   result = new minimally_defined_component_terminal();
   return result;
   }
bool minimally_defined_component_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: minimally_defined_component_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
