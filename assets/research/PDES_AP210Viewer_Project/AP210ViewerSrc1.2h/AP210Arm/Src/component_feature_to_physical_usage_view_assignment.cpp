// Source for AP210 application object
//     component_feature_to_physical_usage_view_assignment

// Precompiled include files
#include <StdAfx.h>

#include "component_feature_to_physical_usage_view_assignment.h"

// Classes
#include <part_feature.h>
#include <component_feature.h>

component_feature_to_physical_usage_view_assignment::component_feature_to_physical_usage_view_assignment() {
   initialize();
   }
component_feature_to_physical_usage_view_assignment::~component_feature_to_physical_usage_view_assignment() {
   // Free string attributes
   }
// intialize data members
void component_feature_to_physical_usage_view_assignment::initialize() {
   // Required attributes
   _defined_part_feature = NULL;
   _assigned_design_object = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_feature_to_physical_usage_view_assignment::DynamicType(int ID) {
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
component_feature_to_physical_usage_view_assignment *component_feature_to_physical_usage_view_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_feature_to_physical_usage_view_assignment *>(s);
      }
   return NULL;
   }
component_feature_to_physical_usage_view_assignment *component_feature_to_physical_usage_view_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_feature_to_physical_usage_view_assignment *>(s);
      }
   return NULL;
   }
// construction factory
component_feature_to_physical_usage_view_assignment *component_feature_to_physical_usage_view_assignment::Construct() {
   component_feature_to_physical_usage_view_assignment *result = NULL;

   // create the component_feature_to_physical_usage_view_assignment.
   result = new component_feature_to_physical_usage_view_assignment();
   return result;
   }
bool component_feature_to_physical_usage_view_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_feature_to_physical_usage_view_assignment\r\n");

   // Check for the existence of all required attributes
   if (_defined_part_feature == NULL) {
      TRACE("ERROR: _defined_part_feature a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_design_object == NULL) {
      TRACE("ERROR: _assigned_design_object a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
