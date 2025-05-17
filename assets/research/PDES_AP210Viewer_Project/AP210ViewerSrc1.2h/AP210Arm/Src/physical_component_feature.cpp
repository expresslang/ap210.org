// Source for AP210 application object
//     physical_component_feature

// Precompiled include files
#include <StdAfx.h>

#include "physical_component_feature.h"

// Classes

physical_component_feature::physical_component_feature() {
   initialize();
   }
physical_component_feature::~physical_component_feature() {
   // Free string attributes
   }
// intialize data members
void physical_component_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int physical_component_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = component_feature::DynamicType(ID);
      }
   if (result == 0) {
      result = physical_feature_or_part_template::DynamicType(ID);
      }
   return result;
   }
physical_component_feature *physical_component_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_component_feature *>(s);
      }
   return NULL;
   }
physical_component_feature *physical_component_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_component_feature *>(s);
      }
   return NULL;
   }
// construction factory
physical_component_feature *physical_component_feature::Construct() {
   physical_component_feature *result = NULL;

   // create the physical_component_feature.
   result = new physical_component_feature();
   return result;
   }
bool physical_component_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_component_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   if (physical_feature_or_part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
