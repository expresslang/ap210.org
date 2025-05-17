// Source for AP210 application object
//     component_feature_relationship

// Precompiled include files
#include <StdAfx.h>

#include "component_feature_relationship.h"

// Classes
#include <component_feature.h>
#include <component_feature.h>

component_feature_relationship::component_feature_relationship() {
   initialize();
   }
component_feature_relationship::~component_feature_relationship() {
   // Free string attributes
   }
// intialize data members
void component_feature_relationship::initialize() {
   // Required attributes
   _related_component_feature = NULL;
   _relating_component_feature = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_feature_relationship::DynamicType(int ID) {
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
component_feature_relationship *component_feature_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_feature_relationship *>(s);
      }
   return NULL;
   }
component_feature_relationship *component_feature_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_feature_relationship *>(s);
      }
   return NULL;
   }
// construction factory
component_feature_relationship *component_feature_relationship::Construct() {
   component_feature_relationship *result = NULL;

   // create the component_feature_relationship.
   result = new component_feature_relationship();
   return result;
   }
bool component_feature_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_feature_relationship\r\n");

   // Check for the existence of all required attributes
   if (_related_component_feature == NULL) {
      TRACE("ERROR: _related_component_feature a required attribute is NULL!\r\n");
      result = false;
      }
   if (_relating_component_feature == NULL) {
      TRACE("ERROR: _relating_component_feature a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
