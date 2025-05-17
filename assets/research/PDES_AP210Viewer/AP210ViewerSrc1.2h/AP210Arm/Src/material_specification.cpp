// Source for AP210 application object
//     material_specification

// Precompiled include files
#include <StdAfx.h>

#include "material_specification.h"

// Classes

material_specification::material_specification() {
   initialize();
   }
material_specification::~material_specification() {
   // Free string attributes
   }
// intialize data members
void material_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int material_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_specification::DynamicType(ID);
      }
   return result;
   }
material_specification *material_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<material_specification *>(s);
      }
   return NULL;
   }
material_specification *material_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<material_specification *>(s);
      }
   return NULL;
   }
// construction factory
material_specification *material_specification::Construct() {
   material_specification *result = NULL;

   // create the material_specification.
   result = new material_specification();
   return result;
   }
bool material_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: material_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_specification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
