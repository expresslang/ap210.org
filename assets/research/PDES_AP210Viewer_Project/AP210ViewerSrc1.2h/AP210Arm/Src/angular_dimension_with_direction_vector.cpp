// Source for AP210 application object
//     angular_dimension_with_direction_vector

// Precompiled include files
#include <StdAfx.h>

#include "angular_dimension_with_direction_vector.h"

// Classes

angular_dimension_with_direction_vector::angular_dimension_with_direction_vector() {
   initialize();
   }
angular_dimension_with_direction_vector::~angular_dimension_with_direction_vector() {
   // Free string attributes
   }
// intialize data members
void angular_dimension_with_direction_vector::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int angular_dimension_with_direction_vector::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = dimensional_location::DynamicType(ID);
      }
   return result;
   }
angular_dimension_with_direction_vector *angular_dimension_with_direction_vector::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<angular_dimension_with_direction_vector *>(s);
      }
   return NULL;
   }
angular_dimension_with_direction_vector *angular_dimension_with_direction_vector::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<angular_dimension_with_direction_vector *>(s);
      }
   return NULL;
   }
// construction factory
angular_dimension_with_direction_vector *angular_dimension_with_direction_vector::Construct() {
   angular_dimension_with_direction_vector *result = NULL;

   // create the angular_dimension_with_direction_vector.
   result = new angular_dimension_with_direction_vector();
   return result;
   }
bool angular_dimension_with_direction_vector::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: angular_dimension_with_direction_vector\r\n");

   // Check for the existence of all required attributes
   if (_measurement_orientation == NULL) {
      TRACE("ERROR: _measurement_orientation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (dimensional_location::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
