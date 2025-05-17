// Source for AP210 application object
//     bare_die_component

// Precompiled include files
#include <StdAfx.h>

#include "bare_die_component.h"

// Classes

bare_die_component::bare_die_component() {
   initialize();
   }
bare_die_component::~bare_die_component() {
   // Free string attributes
   }
// intialize data members
void bare_die_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int bare_die_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_component::DynamicType(ID);
      }
   return result;
   }
bare_die_component *bare_die_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bare_die_component *>(s);
      }
   return NULL;
   }
bare_die_component *bare_die_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bare_die_component *>(s);
      }
   return NULL;
   }
// construction factory
bare_die_component *bare_die_component::Construct() {
   bare_die_component *result = NULL;

   // create the bare_die_component.
   result = new bare_die_component();
   return result;
   }
bool bare_die_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bare_die_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
