// Source for AP210 application object
//     feature_group_relationship

// Precompiled include files
#include <StdAfx.h>

#include "feature_group_relationship.h"

// Classes
#include <part_group_feature.h>

feature_group_relationship::feature_group_relationship() {
   initialize();
   }
feature_group_relationship::~feature_group_relationship() {
   // Free string attributes
   }
// intialize data members
void feature_group_relationship::initialize() {
   // Required attributes
   _relating_feature = NULL;

   // Optional attributes
   }
// Runtime type identification
int feature_group_relationship::DynamicType(int ID) {
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
feature_group_relationship *feature_group_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<feature_group_relationship *>(s);
      }
   return NULL;
   }
feature_group_relationship *feature_group_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<feature_group_relationship *>(s);
      }
   return NULL;
   }
// construction factory
feature_group_relationship *feature_group_relationship::Construct() {
   feature_group_relationship *result = NULL;

   // create the feature_group_relationship.
   result = new feature_group_relationship();
   return result;
   }
bool feature_group_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: feature_group_relationship\r\n");

   // Check for the existence of all required attributes
   if (_relating_feature == NULL) {
      TRACE("ERROR: _relating_feature a required attribute is NULL!\r\n");
      result = false;
      }
   if (_related_feature == NULL) {
      TRACE("ERROR: _related_feature a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
