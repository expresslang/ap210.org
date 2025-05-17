// Source for AP210 application object
//     material_removal_feature_template

// Precompiled include files
#include <StdAfx.h>

#include "material_removal_feature_template.h"

// Classes

material_removal_feature_template::material_removal_feature_template() {
   initialize();
   }
material_removal_feature_template::~material_removal_feature_template() {
   // Free string attributes
   }
// intialize data members
void material_removal_feature_template::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int material_removal_feature_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_template::DynamicType(ID);
      }
   return result;
   }
material_removal_feature_template *material_removal_feature_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<material_removal_feature_template *>(s);
      }
   return NULL;
   }
material_removal_feature_template *material_removal_feature_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<material_removal_feature_template *>(s);
      }
   return NULL;
   }
// construction factory
material_removal_feature_template *material_removal_feature_template::Construct() {
   material_removal_feature_template *result = NULL;

   // create the material_removal_feature_template.
   result = new material_removal_feature_template();
   return result;
   }
bool material_removal_feature_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: material_removal_feature_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
