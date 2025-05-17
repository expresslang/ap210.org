// Source for AP210 application object
//     geometric_tolerance_with_applied_material_condition_property

// Precompiled include files
#include <StdAfx.h>

#include "geometric_tolerance_with_applied_material_condition_property.h"

// Classes

geometric_tolerance_with_applied_material_condition_property::geometric_tolerance_with_applied_material_condition_property() {
   initialize();
   }
geometric_tolerance_with_applied_material_condition_property::~geometric_tolerance_with_applied_material_condition_property() {
   // Free string attributes
   }
// intialize data members
void geometric_tolerance_with_applied_material_condition_property::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int geometric_tolerance_with_applied_material_condition_property::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = geometric_tolerance::DynamicType(ID);
      }
   return result;
   }
geometric_tolerance_with_applied_material_condition_property *geometric_tolerance_with_applied_material_condition_property::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<geometric_tolerance_with_applied_material_condition_property *>(s);
      }
   return NULL;
   }
geometric_tolerance_with_applied_material_condition_property *geometric_tolerance_with_applied_material_condition_property::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<geometric_tolerance_with_applied_material_condition_property *>(s);
      }
   return NULL;
   }
// construction factory
geometric_tolerance_with_applied_material_condition_property *geometric_tolerance_with_applied_material_condition_property::Construct() {
   geometric_tolerance_with_applied_material_condition_property *result = NULL;

   // create the geometric_tolerance_with_applied_material_condition_property.
   result = new geometric_tolerance_with_applied_material_condition_property();
   return result;
   }
bool geometric_tolerance_with_applied_material_condition_property::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: geometric_tolerance_with_applied_material_condition_property\r\n");

   // Check for the existence of all required attributes
   if (_applied_material_condition_property_name == NULL) {
      TRACE("ERROR: _applied_material_condition_property_name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
