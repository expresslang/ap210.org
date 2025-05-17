// Source for AP210 application object
//     thermal_component

// Precompiled include files
#include <StdAfx.h>

#include "thermal_component.h"

// Classes

thermal_component::thermal_component() {
   initialize();
   }
thermal_component::~thermal_component() {
   // Free string attributes
   }
// intialize data members
void thermal_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int thermal_component::DynamicType(int ID) {
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
thermal_component *thermal_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<thermal_component *>(s);
      }
   return NULL;
   }
thermal_component *thermal_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<thermal_component *>(s);
      }
   return NULL;
   }
// construction factory
thermal_component *thermal_component::Construct() {
   thermal_component *result = NULL;

   // create the thermal_component.
   result = new thermal_component();
   return result;
   }
bool thermal_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: thermal_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
