// Source for AP210 application object
//     assembly_module_component_terminal

// Precompiled include files
#include <StdAfx.h>

#include "assembly_module_component_terminal.h"

// Classes

assembly_module_component_terminal::assembly_module_component_terminal() {
   initialize();
   }
assembly_module_component_terminal::~assembly_module_component_terminal() {
   // Free string attributes
   }
// intialize data members
void assembly_module_component_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int assembly_module_component_terminal::DynamicType(int ID) {
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
assembly_module_component_terminal *assembly_module_component_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_module_component_terminal *>(s);
      }
   return NULL;
   }
assembly_module_component_terminal *assembly_module_component_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_module_component_terminal *>(s);
      }
   return NULL;
   }
// construction factory
assembly_module_component_terminal *assembly_module_component_terminal::Construct() {
   assembly_module_component_terminal *result = NULL;

   // create the assembly_module_component_terminal.
   result = new assembly_module_component_terminal();
   return result;
   }
bool assembly_module_component_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_module_component_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
