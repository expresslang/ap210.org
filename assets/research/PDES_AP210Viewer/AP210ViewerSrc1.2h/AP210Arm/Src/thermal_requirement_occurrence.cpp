// Source for AP210 application object
//     thermal_requirement_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "thermal_requirement_occurrence.h"

// Classes

thermal_requirement_occurrence::thermal_requirement_occurrence() {
   initialize();
   }
thermal_requirement_occurrence::~thermal_requirement_occurrence() {
   // Free string attributes
   }
// intialize data members
void thermal_requirement_occurrence::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int thermal_requirement_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_requirement_occurrence::DynamicType(ID);
      }
   return result;
   }
thermal_requirement_occurrence *thermal_requirement_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<thermal_requirement_occurrence *>(s);
      }
   return NULL;
   }
thermal_requirement_occurrence *thermal_requirement_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<thermal_requirement_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
thermal_requirement_occurrence *thermal_requirement_occurrence::Construct() {
   thermal_requirement_occurrence *result = NULL;

   // create the thermal_requirement_occurrence.
   result = new thermal_requirement_occurrence();
   return result;
   }
bool thermal_requirement_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: thermal_requirement_occurrence\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
