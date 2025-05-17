// Source for AP210 application object
//     primary_reference_terminal

// Precompiled include files
#include <StdAfx.h>

#include "primary_reference_terminal.h"

// Classes

primary_reference_terminal::primary_reference_terminal() {
   initialize();
   }
primary_reference_terminal::~primary_reference_terminal() {
   // Free string attributes
   }
// intialize data members
void primary_reference_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int primary_reference_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = package_terminal::DynamicType(ID);
      }
   return result;
   }
primary_reference_terminal *primary_reference_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<primary_reference_terminal *>(s);
      }
   return NULL;
   }
primary_reference_terminal *primary_reference_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<primary_reference_terminal *>(s);
      }
   return NULL;
   }
// construction factory
primary_reference_terminal *primary_reference_terminal::Construct() {
   primary_reference_terminal *result = NULL;

   // create the primary_reference_terminal.
   result = new primary_reference_terminal();
   return result;
   }
bool primary_reference_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: primary_reference_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (package_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
