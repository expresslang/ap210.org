// Source for AP210 application object
//     electrical_network_definition

// Precompiled include files
#include <StdAfx.h>

#include "electrical_network_definition.h"

// Classes

electrical_network_definition::electrical_network_definition() {
   initialize();
   }
electrical_network_definition::~electrical_network_definition() {
   // Free string attributes
   }
// intialize data members
void electrical_network_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int electrical_network_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = functional_unit_network_definition::DynamicType(ID);
      }
   return result;
   }
electrical_network_definition *electrical_network_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<electrical_network_definition *>(s);
      }
   return NULL;
   }
electrical_network_definition *electrical_network_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<electrical_network_definition *>(s);
      }
   return NULL;
   }
// construction factory
electrical_network_definition *electrical_network_definition::Construct() {
   electrical_network_definition *result = NULL;

   // create the electrical_network_definition.
   result = new electrical_network_definition();
   return result;
   }
bool electrical_network_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: electrical_network_definition\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (functional_unit_network_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
