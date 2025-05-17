// Source for AP210 application object
//     component_terminal

// Precompiled include files
#include <StdAfx.h>

#include "component_terminal.h"

// Classes

component_terminal::component_terminal() {
   initialize();
   }
component_terminal::~component_terminal() {
   // Free string attributes
   if (_swap_code != NULL) {
      free(_swap_code);
     }
   }
// intialize data members
void component_terminal::initialize() {
   // Required attributes

   // Optional attributes
   _swap_code = NULL;
   }
// Runtime type identification
int component_terminal::DynamicType(int ID) {
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
component_terminal *component_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_terminal *>(s);
      }
   return NULL;
   }
component_terminal *component_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_terminal *>(s);
      }
   return NULL;
   }
// construction factory
component_terminal *component_terminal::Construct() {
   component_terminal *result = NULL;

   // create the component_terminal.
   result = new component_terminal();
   return result;
   }
bool component_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
