// Source for AP210 application object
//     stratum_feature_3d_shape

// Precompiled include files
#include <StdAfx.h>

#include "stratum_feature_3d_shape.h"

// Classes
#include <stratum_feature.h>
#include <bound_volume_shape.h>

stratum_feature_3d_shape::stratum_feature_3d_shape() {
   initialize();
   }
stratum_feature_3d_shape::~stratum_feature_3d_shape() {
   // Free string attributes
   }
// intialize data members
void stratum_feature_3d_shape::initialize() {
   // Required attributes
   _represented_stratum_feature = NULL;
   _shape_surface_representation = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_feature_3d_shape::DynamicType(int ID) {
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
stratum_feature_3d_shape *stratum_feature_3d_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_feature_3d_shape *>(s);
      }
   return NULL;
   }
stratum_feature_3d_shape *stratum_feature_3d_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_feature_3d_shape *>(s);
      }
   return NULL;
   }
// construction factory
stratum_feature_3d_shape *stratum_feature_3d_shape::Construct() {
   stratum_feature_3d_shape *result = NULL;

   // create the stratum_feature_3d_shape.
   result = new stratum_feature_3d_shape();
   return result;
   }
bool stratum_feature_3d_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_feature_3d_shape\r\n");

   // Check for the existence of all required attributes
   if (_represented_stratum_feature == NULL) {
      TRACE("ERROR: _represented_stratum_feature a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_surface_representation == NULL) {
      TRACE("ERROR: _shape_surface_representation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
