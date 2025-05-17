// Source for AP210 application object
//     via_terminal

// Precompiled include files
#include <StdAfx.h>

#include "via_terminal.h"

// Classes

via_terminal::via_terminal() {
   initialize();
   }
via_terminal::~via_terminal() {
   // Free string attributes
   }
// intialize data members
void via_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int via_terminal::DynamicType(int ID) {
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
via_terminal *via_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<via_terminal *>(s);
      }
   return NULL;
   }
via_terminal *via_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<via_terminal *>(s);
      }
   return NULL;
   }
// construction factory
via_terminal *via_terminal::Construct() {
   via_terminal *result = NULL;

   // create the via_terminal.
   result = new via_terminal();
   return result;
   }
bool via_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: via_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
