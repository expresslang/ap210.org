// Source for AP210 application object
//     datum_feature_usage_in_datum_system_relationship

// Precompiled include files
#include <StdAfx.h>

#include "datum_feature_usage_in_datum_system_relationship.h"

// Classes
#include <datum_system.h>
#include <datum_feature.h>

datum_feature_usage_in_datum_system_relationship::datum_feature_usage_in_datum_system_relationship() {
   initialize();
   }
datum_feature_usage_in_datum_system_relationship::~datum_feature_usage_in_datum_system_relationship() {
   // Free string attributes
   }
// intialize data members
void datum_feature_usage_in_datum_system_relationship::initialize() {
   // Required attributes
   _established_datum_system = NULL;
   _used_datum_feature = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_feature_usage_in_datum_system_relationship::DynamicType(int ID) {
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
datum_feature_usage_in_datum_system_relationship *datum_feature_usage_in_datum_system_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_feature_usage_in_datum_system_relationship *>(s);
      }
   return NULL;
   }
datum_feature_usage_in_datum_system_relationship *datum_feature_usage_in_datum_system_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_feature_usage_in_datum_system_relationship *>(s);
      }
   return NULL;
   }
// construction factory
datum_feature_usage_in_datum_system_relationship *datum_feature_usage_in_datum_system_relationship::Construct() {
   datum_feature_usage_in_datum_system_relationship *result = NULL;

   // create the datum_feature_usage_in_datum_system_relationship.
   result = new datum_feature_usage_in_datum_system_relationship();
   return result;
   }
bool datum_feature_usage_in_datum_system_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_feature_usage_in_datum_system_relationship\r\n");

   // Check for the existence of all required attributes
   if (_established_datum_system == NULL) {
      TRACE("ERROR: _established_datum_system a required attribute is NULL!\r\n");
      result = false;
      }
   if (_used_datum_feature == NULL) {
      TRACE("ERROR: _used_datum_feature a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
