// Source for AP210 application object
//     material_shape_modification

// Precompiled include files
#include <StdAfx.h>

#include "material_shape_modification.h"

// Classes

material_shape_modification::material_shape_modification() {
   initialize();
   }
material_shape_modification::~material_shape_modification() {
   // Free string attributes
   }
// intialize data members
void material_shape_modification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int material_shape_modification::DynamicType(int ID) {
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
material_shape_modification *material_shape_modification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<material_shape_modification *>(s);
      }
   return NULL;
   }
material_shape_modification *material_shape_modification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<material_shape_modification *>(s);
      }
   return NULL;
   }
// construction factory
material_shape_modification *material_shape_modification::Construct() {
   material_shape_modification *result = NULL;

   // create the material_shape_modification.
   result = new material_shape_modification();
   return result;
   }
bool material_shape_modification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: material_shape_modification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (design_intent_modification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
