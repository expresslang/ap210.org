// Source for AP210 application object
//     stratum_feature_shape_stratum_average_surface_shape_relationship

// Precompiled include files
#include <StdAfx.h>

#include "stratum_feature_shape_stratum_average_surface_shape_relationship.h"

// Classes
#include <stratum_feature_non_planar_2d_shape.h>
#include <stratum_average_surface_shape.h>

stratum_feature_shape_stratum_average_surface_shape_relationship::stratum_feature_shape_stratum_average_surface_shape_relationship() {
   initialize();
   }
stratum_feature_shape_stratum_average_surface_shape_relationship::~stratum_feature_shape_stratum_average_surface_shape_relationship() {
   // Free string attributes
   }
// intialize data members
void stratum_feature_shape_stratum_average_surface_shape_relationship::initialize() {
   // Required attributes
   _of_stratum_feature_shape = NULL;
   _of_stratum_average_surface_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_feature_shape_stratum_average_surface_shape_relationship::DynamicType(int ID) {
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
stratum_feature_shape_stratum_average_surface_shape_relationship *stratum_feature_shape_stratum_average_surface_shape_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_feature_shape_stratum_average_surface_shape_relationship *>(s);
      }
   return NULL;
   }
stratum_feature_shape_stratum_average_surface_shape_relationship *stratum_feature_shape_stratum_average_surface_shape_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_feature_shape_stratum_average_surface_shape_relationship *>(s);
      }
   return NULL;
   }
// construction factory
stratum_feature_shape_stratum_average_surface_shape_relationship *stratum_feature_shape_stratum_average_surface_shape_relationship::Construct() {
   stratum_feature_shape_stratum_average_surface_shape_relationship *result = NULL;

   // create the stratum_feature_shape_stratum_average_surface_shape_relationship.
   result = new stratum_feature_shape_stratum_average_surface_shape_relationship();
   return result;
   }
bool stratum_feature_shape_stratum_average_surface_shape_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_feature_shape_stratum_average_surface_shape_relationship\r\n");

   // Check for the existence of all required attributes
   if (_of_stratum_feature_shape == NULL) {
      TRACE("ERROR: _of_stratum_feature_shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_of_stratum_average_surface_shape == NULL) {
      TRACE("ERROR: _of_stratum_average_surface_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
