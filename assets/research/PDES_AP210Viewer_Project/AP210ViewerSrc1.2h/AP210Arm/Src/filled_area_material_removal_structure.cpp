// Source for AP210 application object
//     filled_area_material_removal_structure

// Precompiled include files
#include <StdAfx.h>

#include "filled_area_material_removal_structure.h"

// Classes

filled_area_material_removal_structure::filled_area_material_removal_structure() {
   initialize();
   }
filled_area_material_removal_structure::~filled_area_material_removal_structure() {
   // Free string attributes
   }
// intialize data members
void filled_area_material_removal_structure::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int filled_area_material_removal_structure::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = material_removal_feature::DynamicType(ID);
      }
   return result;
   }
filled_area_material_removal_structure *filled_area_material_removal_structure::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<filled_area_material_removal_structure *>(s);
      }
   return NULL;
   }
filled_area_material_removal_structure *filled_area_material_removal_structure::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<filled_area_material_removal_structure *>(s);
      }
   return NULL;
   }
// construction factory
filled_area_material_removal_structure *filled_area_material_removal_structure::Construct() {
   filled_area_material_removal_structure *result = NULL;

   // create the filled_area_material_removal_structure.
   result = new filled_area_material_removal_structure();
   return result;
   }
bool filled_area_material_removal_structure::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: filled_area_material_removal_structure\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (material_removal_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
