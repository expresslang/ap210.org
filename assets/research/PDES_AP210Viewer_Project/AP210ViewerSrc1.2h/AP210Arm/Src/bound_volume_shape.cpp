// Source for AP210 application object
//     bound_volume_shape

// Precompiled include files
#include <StdAfx.h>

#include "bound_volume_shape.h"

// Classes

bound_volume_shape::bound_volume_shape() {
   initialize();
   }
bound_volume_shape::~bound_volume_shape() {
   // Free string attributes
   }
// intialize data members
void bound_volume_shape::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int bound_volume_shape::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = feature_shape_definition::DynamicType(ID);
      }
   return result;
   }
bound_volume_shape *bound_volume_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bound_volume_shape *>(s);
      }
   return NULL;
   }
bound_volume_shape *bound_volume_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bound_volume_shape *>(s);
      }
   return NULL;
   }
// construction factory
bound_volume_shape *bound_volume_shape::Construct() {
   bound_volume_shape *result = NULL;

   // create the bound_volume_shape.
   result = new bound_volume_shape();
   return result;
   }
bool bound_volume_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bound_volume_shape\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (feature_shape_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
