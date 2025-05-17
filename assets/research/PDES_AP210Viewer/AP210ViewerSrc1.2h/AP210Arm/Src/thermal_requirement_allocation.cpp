// Source for AP210 application object
//     thermal_requirement_allocation

// Precompiled include files
#include <StdAfx.h>

#include "thermal_requirement_allocation.h"

// Classes

thermal_requirement_allocation::thermal_requirement_allocation() {
   initialize();
   }
thermal_requirement_allocation::~thermal_requirement_allocation() {
   // Free string attributes
   }
// intialize data members
void thermal_requirement_allocation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int thermal_requirement_allocation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_requirement_allocation::DynamicType(ID);
      }
   return result;
   }
thermal_requirement_allocation *thermal_requirement_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<thermal_requirement_allocation *>(s);
      }
   return NULL;
   }
thermal_requirement_allocation *thermal_requirement_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<thermal_requirement_allocation *>(s);
      }
   return NULL;
   }
// construction factory
thermal_requirement_allocation *thermal_requirement_allocation::Construct() {
   thermal_requirement_allocation *result = NULL;

   // create the thermal_requirement_allocation.
   result = new thermal_requirement_allocation();
   return result;
   }
bool thermal_requirement_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: thermal_requirement_allocation\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_requirement_allocation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
