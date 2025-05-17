// Source for AP210 application object
//     feature_shape_definition

// Precompiled include files
#include <StdAfx.h>

#include "feature_shape_definition.h"

// Classes
#include <cartesian_coordinate_system.h>

feature_shape_definition::feature_shape_definition() {
   initialize();
   }
feature_shape_definition::~feature_shape_definition() {
   // Free string attributes
   }
// intialize data members
void feature_shape_definition::initialize() {
   // Required attributes
   _geometric_context = NULL;

   // Optional attributes
   }
// Runtime type identification
int feature_shape_definition::DynamicType(int ID) {
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
feature_shape_definition *feature_shape_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<feature_shape_definition *>(s);
      }
   return NULL;
   }
feature_shape_definition *feature_shape_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<feature_shape_definition *>(s);
      }
   return NULL;
   }
// construction factory
feature_shape_definition *feature_shape_definition::Construct() {
   feature_shape_definition *result = NULL;

   // create the feature_shape_definition.
   result = new feature_shape_definition();
   return result;
   }
bool feature_shape_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: feature_shape_definition\r\n");

   // Check for the existence of all required attributes
   if (_geometric_context == NULL) {
      TRACE("ERROR: _geometric_context a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
