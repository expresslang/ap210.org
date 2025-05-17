// Source for AP210 application object
//     stratum_feature_styled_area_representation

// Precompiled include files
#include <StdAfx.h>

#include "stratum_feature_styled_area_representation.h"

// Classes
#include <stratum_feature.h>

stratum_feature_styled_area_representation::stratum_feature_styled_area_representation() {
   initialize();
   }
stratum_feature_styled_area_representation::~stratum_feature_styled_area_representation() {
   // Free string attributes
   }
// intialize data members
void stratum_feature_styled_area_representation::initialize() {
   // Required attributes
   _represented_stratum_feature = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_feature_styled_area_representation::DynamicType(int ID) {
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
stratum_feature_styled_area_representation *stratum_feature_styled_area_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_feature_styled_area_representation *>(s);
      }
   return NULL;
   }
stratum_feature_styled_area_representation *stratum_feature_styled_area_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_feature_styled_area_representation *>(s);
      }
   return NULL;
   }
// construction factory
stratum_feature_styled_area_representation *stratum_feature_styled_area_representation::Construct() {
   stratum_feature_styled_area_representation *result = NULL;

   // create the stratum_feature_styled_area_representation.
   result = new stratum_feature_styled_area_representation();
   return result;
   }
bool stratum_feature_styled_area_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_feature_styled_area_representation\r\n");

   // Check for the existence of all required attributes
   if (_shape_styled_area_representation == NULL) {
      TRACE("ERROR: _shape_styled_area_representation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_represented_stratum_feature == NULL) {
      TRACE("ERROR: _represented_stratum_feature a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
