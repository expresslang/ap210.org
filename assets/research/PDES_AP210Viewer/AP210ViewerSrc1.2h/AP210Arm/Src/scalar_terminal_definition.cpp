// Source for AP210 application object
//     scalar_terminal_definition

// Precompiled include files
#include <StdAfx.h>

#include "scalar_terminal_definition.h"

// Classes

scalar_terminal_definition::scalar_terminal_definition() {
   initialize();
   }
scalar_terminal_definition::~scalar_terminal_definition() {
   // Free string attributes
   }
// intialize data members
void scalar_terminal_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int scalar_terminal_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = functional_unit_usage_view_terminal_definition::DynamicType(ID);
      }
   return result;
   }
scalar_terminal_definition *scalar_terminal_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<scalar_terminal_definition *>(s);
      }
   return NULL;
   }
scalar_terminal_definition *scalar_terminal_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<scalar_terminal_definition *>(s);
      }
   return NULL;
   }
// construction factory
scalar_terminal_definition *scalar_terminal_definition::Construct() {
   scalar_terminal_definition *result = NULL;

   // create the scalar_terminal_definition.
   result = new scalar_terminal_definition();
   return result;
   }
bool scalar_terminal_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: scalar_terminal_definition\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (functional_unit_usage_view_terminal_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
