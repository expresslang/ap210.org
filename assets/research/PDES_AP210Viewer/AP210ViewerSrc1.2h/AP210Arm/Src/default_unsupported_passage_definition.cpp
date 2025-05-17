// Source for AP210 application object
//     default_unsupported_passage_definition

// Precompiled include files
#include <StdAfx.h>

#include "default_unsupported_passage_definition.h"

// Classes

default_unsupported_passage_definition::default_unsupported_passage_definition() {
   initialize();
   }
default_unsupported_passage_definition::~default_unsupported_passage_definition() {
   // Free string attributes
   }
// intialize data members
void default_unsupported_passage_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int default_unsupported_passage_definition::DynamicType(int ID) {
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
default_unsupported_passage_definition *default_unsupported_passage_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<default_unsupported_passage_definition *>(s);
      }
   return NULL;
   }
default_unsupported_passage_definition *default_unsupported_passage_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<default_unsupported_passage_definition *>(s);
      }
   return NULL;
   }
// construction factory
default_unsupported_passage_definition *default_unsupported_passage_definition::Construct() {
   default_unsupported_passage_definition *result = NULL;

   // create the default_unsupported_passage_definition.
   result = new default_unsupported_passage_definition();
   return result;
   }
bool default_unsupported_passage_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: default_unsupported_passage_definition\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (passage_technology::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
