// Source for AP210 application object
//     non_functional_land_join_terminal

// Precompiled include files
#include <StdAfx.h>

#include "non_functional_land_join_terminal.h"

// Classes

non_functional_land_join_terminal::non_functional_land_join_terminal() {
   initialize();
   }
non_functional_land_join_terminal::~non_functional_land_join_terminal() {
   // Free string attributes
   }
// intialize data members
void non_functional_land_join_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int non_functional_land_join_terminal::DynamicType(int ID) {
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
non_functional_land_join_terminal *non_functional_land_join_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<non_functional_land_join_terminal *>(s);
      }
   return NULL;
   }
non_functional_land_join_terminal *non_functional_land_join_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<non_functional_land_join_terminal *>(s);
      }
   return NULL;
   }
// construction factory
non_functional_land_join_terminal *non_functional_land_join_terminal::Construct() {
   non_functional_land_join_terminal *result = NULL;

   // create the non_functional_land_join_terminal.
   result = new non_functional_land_join_terminal();
   return result;
   }
bool non_functional_land_join_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: non_functional_land_join_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
