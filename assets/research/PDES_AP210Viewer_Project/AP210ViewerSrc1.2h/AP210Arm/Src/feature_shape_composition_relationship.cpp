// Source for AP210 application object
//     feature_shape_composition_relationship

// Precompiled include files
#include <StdAfx.h>

#include "feature_shape_composition_relationship.h"

// Classes
#include <feature_shape_occurrence.h>
#include <feature_shape_definition.h>
#include <axis_placement.h>

feature_shape_composition_relationship::feature_shape_composition_relationship() {
   initialize();
   }
feature_shape_composition_relationship::~feature_shape_composition_relationship() {
   // Free string attributes
   }
// intialize data members
void feature_shape_composition_relationship::initialize() {
   // Required attributes
   _related_feature_shape = NULL;
   _resultant_feature_shape = NULL;
   _related_feature_shape_placement = NULL;

   // Optional attributes
   }
// Runtime type identification
int feature_shape_composition_relationship::DynamicType(int ID) {
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
feature_shape_composition_relationship *feature_shape_composition_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<feature_shape_composition_relationship *>(s);
      }
   return NULL;
   }
feature_shape_composition_relationship *feature_shape_composition_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<feature_shape_composition_relationship *>(s);
      }
   return NULL;
   }
// construction factory
feature_shape_composition_relationship *feature_shape_composition_relationship::Construct() {
   feature_shape_composition_relationship *result = NULL;

   // create the feature_shape_composition_relationship.
   result = new feature_shape_composition_relationship();
   return result;
   }
bool feature_shape_composition_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: feature_shape_composition_relationship\r\n");

   // Check for the existence of all required attributes
   if (_related_feature_shape == NULL) {
      TRACE("ERROR: _related_feature_shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_resultant_feature_shape == NULL) {
      TRACE("ERROR: _resultant_feature_shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_related_feature_shape_placement == NULL) {
      TRACE("ERROR: _related_feature_shape_placement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
