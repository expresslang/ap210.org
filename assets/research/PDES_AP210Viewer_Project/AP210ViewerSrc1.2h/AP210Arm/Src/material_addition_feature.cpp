// Source for AP210 application object
//     material_addition_feature

// Precompiled include files
#include <StdAfx.h>

#include "material_addition_feature.h"

// Classes

material_addition_feature::material_addition_feature() {
   initialize();
   }
material_addition_feature::~material_addition_feature() {
   // Free string attributes
   }
// intialize data members
void material_addition_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int material_addition_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = design_intent_modification::DynamicType(ID);
      }
   return result;
   }
material_addition_feature *material_addition_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<material_addition_feature *>(s);
      }
   return NULL;
   }
material_addition_feature *material_addition_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<material_addition_feature *>(s);
      }
   return NULL;
   }
// construction factory
material_addition_feature *material_addition_feature::Construct() {
   material_addition_feature *result = NULL;

   // create the material_addition_feature.
   result = new material_addition_feature();
   return result;
   }
bool material_addition_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: material_addition_feature\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (design_intent_modification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
