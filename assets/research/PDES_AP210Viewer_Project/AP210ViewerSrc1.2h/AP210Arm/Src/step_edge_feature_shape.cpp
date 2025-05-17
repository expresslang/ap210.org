// Source for AP210 application object
//     step_edge_feature_shape

// Precompiled include files
#include <StdAfx.h>

#include "step_edge_feature_shape.h"

// Classes
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>

step_edge_feature_shape::step_edge_feature_shape() {
   initialize();
   }
step_edge_feature_shape::~step_edge_feature_shape() {
   // Free string attributes
   }
// intialize data members
void step_edge_feature_shape::initialize() {
   // Required attributes
   _minimum_step_width = NULL;
   _maximum_step_width = NULL;
   _maximum_step_depth = NULL;
   _minimum_step_depth = NULL;

   // Optional attributes
   }
// Runtime type identification
int step_edge_feature_shape::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = edge_shape::DynamicType(ID);
      }
   return result;
   }
step_edge_feature_shape *step_edge_feature_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<step_edge_feature_shape *>(s);
      }
   return NULL;
   }
step_edge_feature_shape *step_edge_feature_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<step_edge_feature_shape *>(s);
      }
   return NULL;
   }
// construction factory
step_edge_feature_shape *step_edge_feature_shape::Construct() {
   step_edge_feature_shape *result = NULL;

   // create the step_edge_feature_shape.
   result = new step_edge_feature_shape();
   return result;
   }
bool step_edge_feature_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: step_edge_feature_shape\r\n");

   // Check for the existence of all required attributes
   if (_minimum_step_width == NULL) {
      TRACE("ERROR: _minimum_step_width a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_step_width == NULL) {
      TRACE("ERROR: _maximum_step_width a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_step_depth == NULL) {
      TRACE("ERROR: _maximum_step_depth a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_step_depth == NULL) {
      TRACE("ERROR: _minimum_step_depth a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (edge_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
