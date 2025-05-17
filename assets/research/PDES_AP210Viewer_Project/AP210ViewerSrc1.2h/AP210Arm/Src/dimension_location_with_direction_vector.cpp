// Source for AP210 application object
//     dimension_location_with_direction_vector

// Precompiled include files
#include <StdAfx.h>

#include "dimension_location_with_direction_vector.h"

// Classes

dimension_location_with_direction_vector::dimension_location_with_direction_vector() {
   initialize();
   }
dimension_location_with_direction_vector::~dimension_location_with_direction_vector() {
   // Free string attributes
   }
// intialize data members
void dimension_location_with_direction_vector::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int dimension_location_with_direction_vector::DynamicType(int ID) {
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
dimension_location_with_direction_vector *dimension_location_with_direction_vector::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimension_location_with_direction_vector *>(s);
      }
   return NULL;
   }
dimension_location_with_direction_vector *dimension_location_with_direction_vector::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimension_location_with_direction_vector *>(s);
      }
   return NULL;
   }
// construction factory
dimension_location_with_direction_vector *dimension_location_with_direction_vector::Construct() {
   dimension_location_with_direction_vector *result = NULL;

   // create the dimension_location_with_direction_vector.
   result = new dimension_location_with_direction_vector();
   return result;
   }
bool dimension_location_with_direction_vector::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimension_location_with_direction_vector\r\n");

   // Check for the existence of all required attributes
   if (_measurement_direction == NULL) {
      TRACE("ERROR: _measurement_direction a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (dimensional_location::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
