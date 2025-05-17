// Source for AP210 application object
//     bare_die_component_terminal

// Precompiled include files
#include <StdAfx.h>

#include "bare_die_component_terminal.h"

// Classes

bare_die_component_terminal::bare_die_component_terminal() {
   initialize();
   }
bare_die_component_terminal::~bare_die_component_terminal() {
   // Free string attributes
   }
// intialize data members
void bare_die_component_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int bare_die_component_terminal::DynamicType(int ID) {
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
bare_die_component_terminal *bare_die_component_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bare_die_component_terminal *>(s);
      }
   return NULL;
   }
bare_die_component_terminal *bare_die_component_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bare_die_component_terminal *>(s);
      }
   return NULL;
   }
// construction factory
bare_die_component_terminal *bare_die_component_terminal::Construct() {
   bare_die_component_terminal *result = NULL;

   // create the bare_die_component_terminal.
   result = new bare_die_component_terminal();
   return result;
   }
bool bare_die_component_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bare_die_component_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
