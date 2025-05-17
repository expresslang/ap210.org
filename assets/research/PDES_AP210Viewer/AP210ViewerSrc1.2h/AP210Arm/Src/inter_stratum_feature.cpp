// Source for AP210 application object
//     inter_stratum_feature

// Precompiled include files
#include <StdAfx.h>

#include "inter_stratum_feature.h"

// Classes

inter_stratum_feature::inter_stratum_feature() {
   initialize();
   }
inter_stratum_feature::~inter_stratum_feature() {
   // Free string attributes
   }
// intialize data members
void inter_stratum_feature::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int inter_stratum_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = laminate_component::DynamicType(ID);
      }
   if (result == 0) {
      result = physical_feature_or_part_template::DynamicType(ID);
      }
   return result;
   }
inter_stratum_feature *inter_stratum_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<inter_stratum_feature *>(s);
      }
   return NULL;
   }
inter_stratum_feature *inter_stratum_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<inter_stratum_feature *>(s);
      }
   return NULL;
   }
// construction factory
inter_stratum_feature *inter_stratum_feature::Construct() {
   inter_stratum_feature *result = NULL;

   // create the inter_stratum_feature.
   result = new inter_stratum_feature();
   return result;
   }
bool inter_stratum_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: inter_stratum_feature\r\n");

   // Check for the existence of all required attributes
   if (_feature_of_size == NULL) {
      TRACE("ERROR: _feature_of_size a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   if (physical_feature_or_part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
