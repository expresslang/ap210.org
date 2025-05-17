// Source for AP210 application object
//     datum_feature_material_condition_property

// Precompiled include files
#include <StdAfx.h>

#include "datum_feature_material_condition_property.h"

// Classes
#include <datum_feature_usage_in_datum_system_relationship.h>

datum_feature_material_condition_property::datum_feature_material_condition_property() {
   initialize();
   }
datum_feature_material_condition_property::~datum_feature_material_condition_property() {
   // Free string attributes
   }
// intialize data members
void datum_feature_material_condition_property::initialize() {
   // Required attributes
   _applied_to = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_feature_material_condition_property::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
datum_feature_material_condition_property *datum_feature_material_condition_property::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_feature_material_condition_property *>(s);
      }
   return NULL;
   }
datum_feature_material_condition_property *datum_feature_material_condition_property::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_feature_material_condition_property *>(s);
      }
   return NULL;
   }
// construction factory
datum_feature_material_condition_property *datum_feature_material_condition_property::Construct() {
   datum_feature_material_condition_property *result = NULL;

   // create the datum_feature_material_condition_property.
   result = new datum_feature_material_condition_property();
   return result;
   }
bool datum_feature_material_condition_property::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_feature_material_condition_property\r\n");

   // Check for the existence of all required attributes
   if (_applied_to == NULL) {
      TRACE("ERROR: _applied_to a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
