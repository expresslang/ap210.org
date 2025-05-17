// Source for AP210 application object
//     assembly_module_terminal

// Precompiled include files
#include <StdAfx.h>

#include "assembly_module_terminal.h"

// Classes
#include <packaged_part_interface_terminal.h>
#include <assembly_module_usage_view_connector_relationship.h>

assembly_module_terminal::assembly_module_terminal() {
   initialize();
   }
assembly_module_terminal::~assembly_module_terminal() {
   // Free string attributes
   }
// intialize data members
void assembly_module_terminal::initialize() {
   // Required attributes

   // Optional attributes
   _reference_terminal = NULL;
   _related_connector = NULL;
   }
// Runtime type identification
int assembly_module_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_terminal::DynamicType(ID);
      }
   return result;
   }
assembly_module_terminal *assembly_module_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_module_terminal *>(s);
      }
   return NULL;
   }
assembly_module_terminal *assembly_module_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_module_terminal *>(s);
      }
   return NULL;
   }
// construction factory
assembly_module_terminal *assembly_module_terminal::Construct() {
   assembly_module_terminal *result = NULL;

   // create the assembly_module_terminal.
   result = new assembly_module_terminal();
   return result;
   }
bool assembly_module_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_module_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
