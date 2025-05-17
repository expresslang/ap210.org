// Source for AP210 application object
//     feature_shape_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "feature_shape_occurrence.h"

// Classes
#include <feature_shape_definition.h>

feature_shape_occurrence::feature_shape_occurrence() {
   initialize();
   }
feature_shape_occurrence::~feature_shape_occurrence() {
   // Free string attributes
   }
// intialize data members
void feature_shape_occurrence::initialize() {
   // Required attributes
   _instantiated_feature_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int feature_shape_occurrence::DynamicType(int ID) {
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
feature_shape_occurrence *feature_shape_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<feature_shape_occurrence *>(s);
      }
   return NULL;
   }
feature_shape_occurrence *feature_shape_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<feature_shape_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
feature_shape_occurrence *feature_shape_occurrence::Construct() {
   feature_shape_occurrence *result = NULL;

   // create the feature_shape_occurrence.
   result = new feature_shape_occurrence();
   return result;
   }
bool feature_shape_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: feature_shape_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_instantiated_feature_shape == NULL) {
      TRACE("ERROR: _instantiated_feature_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
