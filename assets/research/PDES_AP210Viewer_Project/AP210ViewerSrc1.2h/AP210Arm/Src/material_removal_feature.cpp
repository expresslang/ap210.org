// Source for AP210 application object
//     material_removal_feature

// Precompiled include files
#include <StdAfx.h>

#include "material_removal_feature.h"

// Classes
#include <material_removal_feature_template.h>

material_removal_feature::material_removal_feature() {
   initialize();
   }
material_removal_feature::~material_removal_feature() {
   // Free string attributes
   }
// intialize data members
void material_removal_feature::initialize() {
   // Required attributes
   _material_removal_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int material_removal_feature::DynamicType(int ID) {
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
material_removal_feature *material_removal_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<material_removal_feature *>(s);
      }
   return NULL;
   }
material_removal_feature *material_removal_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<material_removal_feature *>(s);
      }
   return NULL;
   }
// construction factory
material_removal_feature *material_removal_feature::Construct() {
   material_removal_feature *result = NULL;

   // create the material_removal_feature.
   result = new material_removal_feature();
   return result;
   }
bool material_removal_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: material_removal_feature\r\n");

   // Check for the existence of all required attributes
   if (_material_removal_shape == NULL) {
      TRACE("ERROR: _material_removal_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (design_intent_modification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
