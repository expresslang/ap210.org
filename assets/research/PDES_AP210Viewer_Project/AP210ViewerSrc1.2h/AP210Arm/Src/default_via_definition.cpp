// Source for AP210 application object
//     default_via_definition

// Precompiled include files
#include <StdAfx.h>

#include "default_via_definition.h"

// Classes

default_via_definition::default_via_definition() {
   initialize();
   }
default_via_definition::~default_via_definition() {
   // Free string attributes
   }
// intialize data members
void default_via_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int default_via_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = passage_technology::DynamicType(ID);
      }
   return result;
   }
default_via_definition *default_via_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<default_via_definition *>(s);
      }
   return NULL;
   }
default_via_definition *default_via_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<default_via_definition *>(s);
      }
   return NULL;
   }
// construction factory
default_via_definition *default_via_definition::Construct() {
   default_via_definition *result = NULL;

   // create the default_via_definition.
   result = new default_via_definition();
   return result;
   }
bool default_via_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: default_via_definition\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (passage_technology::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
