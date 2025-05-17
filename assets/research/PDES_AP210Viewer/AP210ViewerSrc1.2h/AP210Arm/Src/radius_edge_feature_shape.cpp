// Source for AP210 application object
//     radius_edge_feature_shape

// Precompiled include files
#include <StdAfx.h>

#include "radius_edge_feature_shape.h"

// Classes
#include <length_data_element.h>
#include <length_data_element.h>

radius_edge_feature_shape::radius_edge_feature_shape() {
   initialize();
   }
radius_edge_feature_shape::~radius_edge_feature_shape() {
   // Free string attributes
   }
// intialize data members
void radius_edge_feature_shape::initialize() {
   // Required attributes
   _minimum_radius_length = NULL;
   _maximum_radius_length = NULL;

   // Optional attributes
   }
// Runtime type identification
int radius_edge_feature_shape::DynamicType(int ID) {
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
radius_edge_feature_shape *radius_edge_feature_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<radius_edge_feature_shape *>(s);
      }
   return NULL;
   }
radius_edge_feature_shape *radius_edge_feature_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<radius_edge_feature_shape *>(s);
      }
   return NULL;
   }
// construction factory
radius_edge_feature_shape *radius_edge_feature_shape::Construct() {
   radius_edge_feature_shape *result = NULL;

   // create the radius_edge_feature_shape.
   result = new radius_edge_feature_shape();
   return result;
   }
bool radius_edge_feature_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: radius_edge_feature_shape\r\n");

   // Check for the existence of all required attributes
   if (_minimum_radius_length == NULL) {
      TRACE("ERROR: _minimum_radius_length a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_radius_length == NULL) {
      TRACE("ERROR: _maximum_radius_length a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (edge_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
