// Source for AP210 application object
//     thermal_network_definition

// Precompiled include files
#include <StdAfx.h>

#include "thermal_network_definition.h"

// Classes

thermal_network_definition::thermal_network_definition() {
   initialize();
   }
thermal_network_definition::~thermal_network_definition() {
   // Free string attributes
   }
// intialize data members
void thermal_network_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int thermal_network_definition::DynamicType(int ID) {
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
thermal_network_definition *thermal_network_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<thermal_network_definition *>(s);
      }
   return NULL;
   }
thermal_network_definition *thermal_network_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<thermal_network_definition *>(s);
      }
   return NULL;
   }
// construction factory
thermal_network_definition *thermal_network_definition::Construct() {
   thermal_network_definition *result = NULL;

   // create the thermal_network_definition.
   result = new thermal_network_definition();
   return result;
   }
bool thermal_network_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: thermal_network_definition\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (functional_unit_network_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
