// Source for AP210 application object
//     physical_feature_or_part_template

// Precompiled include files
#include <StdAfx.h>

#include "physical_feature_or_part_template.h"

// Classes

physical_feature_or_part_template::physical_feature_or_part_template() {
   initialize();
   }
physical_feature_or_part_template::~physical_feature_or_part_template() {
   // Free string attributes
   }
// intialize data members
void physical_feature_or_part_template::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int physical_feature_or_part_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = shape_element::DynamicType(ID);
      }
   return result;
   }
physical_feature_or_part_template *physical_feature_or_part_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_feature_or_part_template *>(s);
      }
   return NULL;
   }
physical_feature_or_part_template *physical_feature_or_part_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_feature_or_part_template *>(s);
      }
   return NULL;
   }
// construction factory
physical_feature_or_part_template *physical_feature_or_part_template::Construct() {
   physical_feature_or_part_template *result = NULL;

   // create the physical_feature_or_part_template.
   result = new physical_feature_or_part_template();
   return result;
   }
bool physical_feature_or_part_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_feature_or_part_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
