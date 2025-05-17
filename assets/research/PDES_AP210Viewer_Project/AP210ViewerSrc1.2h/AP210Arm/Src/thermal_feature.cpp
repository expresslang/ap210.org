// Source for AP210 application object
//     thermal_feature

// Precompiled include files
#include <StdAfx.h>

#include "thermal_feature.h"

// Classes

thermal_feature::thermal_feature() {
   initialize();
   }
thermal_feature::~thermal_feature() {
   // Free string attributes
   }
// intialize data members
void thermal_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int thermal_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_feature::DynamicType(ID);
      }
   return result;
   }
thermal_feature *thermal_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<thermal_feature *>(s);
      }
   return NULL;
   }
thermal_feature *thermal_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<thermal_feature *>(s);
      }
   return NULL;
   }
// construction factory
thermal_feature *thermal_feature::Construct() {
   thermal_feature *result = NULL;

   // create the thermal_feature.
   result = new thermal_feature();
   return result;
   }
bool thermal_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: thermal_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
