// Source for AP210 application object
//     terminal_swap_specification

// Precompiled include files
#include <StdAfx.h>

#include "terminal_swap_specification.h"

// Classes

terminal_swap_specification::terminal_swap_specification() {
   initialize();
   }
terminal_swap_specification::~terminal_swap_specification() {
   // Free string attributes
   }
// intialize data members
void terminal_swap_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int terminal_swap_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = change_design_object_management_relationship::DynamicType(ID);
      }
   return result;
   }
terminal_swap_specification *terminal_swap_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<terminal_swap_specification *>(s);
      }
   return NULL;
   }
terminal_swap_specification *terminal_swap_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<terminal_swap_specification *>(s);
      }
   return NULL;
   }
// construction factory
terminal_swap_specification *terminal_swap_specification::Construct() {
   terminal_swap_specification *result = NULL;

   // create the terminal_swap_specification.
   result = new terminal_swap_specification();
   return result;
   }
bool terminal_swap_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: terminal_swap_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (change_design_object_management_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
