// Source for AP210 application object
//     SetOfdatum_feature_material_condition_property

// Precompiled include files
#include <StdAfx.h>

#include "SetOfdatum_feature_material_condition_property.h"

// Classes
#include <datum_feature_material_condition_property.h>

SetOfdatum_feature_material_condition_property::SetOfdatum_feature_material_condition_property() {
   initialize();
   }
SetOfdatum_feature_material_condition_property::~SetOfdatum_feature_material_condition_property() {
   // Free string attributes
   }
// intialize data members
void SetOfdatum_feature_material_condition_property::initialize() {
   // Required attributes
   _datum_feature_material_condition_property = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfdatum_feature_material_condition_property::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfdatum_feature_material_condition_property *SetOfdatum_feature_material_condition_property::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfdatum_feature_material_condition_property *>(s);
      }
   return NULL;
   }
SetOfdatum_feature_material_condition_property *SetOfdatum_feature_material_condition_property::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfdatum_feature_material_condition_property *>(s);
      }
   return NULL;
   }
// construction factory
SetOfdatum_feature_material_condition_property *SetOfdatum_feature_material_condition_property::Construct() {
   SetOfdatum_feature_material_condition_property *result = NULL;

   // create the SetOfdatum_feature_material_condition_property.
   result = new SetOfdatum_feature_material_condition_property();
   return result;
   }
bool SetOfdatum_feature_material_condition_property::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfdatum_feature_material_condition_property\r\n");

   // Check for the existence of all required attributes
   if (_datum_feature_material_condition_property == NULL) {
      TRACE("ERROR: _datum_feature_material_condition_property a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
