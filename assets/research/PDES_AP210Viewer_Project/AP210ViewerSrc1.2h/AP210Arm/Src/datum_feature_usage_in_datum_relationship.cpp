// Source for AP210 application object
//     datum_feature_usage_in_datum_relationship

// Precompiled include files
#include <StdAfx.h>

#include "datum_feature_usage_in_datum_relationship.h"

// Classes

datum_feature_usage_in_datum_relationship::datum_feature_usage_in_datum_relationship() {
   initialize();
   }
datum_feature_usage_in_datum_relationship::~datum_feature_usage_in_datum_relationship() {
   // Free string attributes
   }
// intialize data members
void datum_feature_usage_in_datum_relationship::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int datum_feature_usage_in_datum_relationship::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = shape_element_relationship::DynamicType(ID);
      }
   return result;
   }
datum_feature_usage_in_datum_relationship *datum_feature_usage_in_datum_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_feature_usage_in_datum_relationship *>(s);
      }
   return NULL;
   }
datum_feature_usage_in_datum_relationship *datum_feature_usage_in_datum_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_feature_usage_in_datum_relationship *>(s);
      }
   return NULL;
   }
// construction factory
datum_feature_usage_in_datum_relationship *datum_feature_usage_in_datum_relationship::Construct() {
   datum_feature_usage_in_datum_relationship *result = NULL;

   // create the datum_feature_usage_in_datum_relationship.
   result = new datum_feature_usage_in_datum_relationship();
   return result;
   }
bool datum_feature_usage_in_datum_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_feature_usage_in_datum_relationship\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (shape_element_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
