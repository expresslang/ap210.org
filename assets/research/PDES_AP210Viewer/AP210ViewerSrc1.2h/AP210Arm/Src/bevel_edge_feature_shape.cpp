// Source for AP210 application object
//     bevel_edge_feature_shape

// Precompiled include files
#include <StdAfx.h>

#include "bevel_edge_feature_shape.h"

// Classes
#include <length_data_element.h>
#include <angle_data_element.h>
#include <length_data_element.h>
#include <angle_data_element.h>

bevel_edge_feature_shape::bevel_edge_feature_shape() {
   initialize();
   }
bevel_edge_feature_shape::~bevel_edge_feature_shape() {
   // Free string attributes
   }
// intialize data members
void bevel_edge_feature_shape::initialize() {
   // Required attributes
   _minimum_bevel_width = NULL;
   _minimum_bevel_angle = NULL;
   _maximum_bevel_width = NULL;
   _maximum_bevel_angle = NULL;

   // Optional attributes
   }
// Runtime type identification
int bevel_edge_feature_shape::DynamicType(int ID) {
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
bevel_edge_feature_shape *bevel_edge_feature_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bevel_edge_feature_shape *>(s);
      }
   return NULL;
   }
bevel_edge_feature_shape *bevel_edge_feature_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bevel_edge_feature_shape *>(s);
      }
   return NULL;
   }
// construction factory
bevel_edge_feature_shape *bevel_edge_feature_shape::Construct() {
   bevel_edge_feature_shape *result = NULL;

   // create the bevel_edge_feature_shape.
   result = new bevel_edge_feature_shape();
   return result;
   }
bool bevel_edge_feature_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bevel_edge_feature_shape\r\n");

   // Check for the existence of all required attributes
   if (_minimum_bevel_width == NULL) {
      TRACE("ERROR: _minimum_bevel_width a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_bevel_angle == NULL) {
      TRACE("ERROR: _minimum_bevel_angle a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_bevel_width == NULL) {
      TRACE("ERROR: _maximum_bevel_width a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_bevel_angle == NULL) {
      TRACE("ERROR: _maximum_bevel_angle a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (edge_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
