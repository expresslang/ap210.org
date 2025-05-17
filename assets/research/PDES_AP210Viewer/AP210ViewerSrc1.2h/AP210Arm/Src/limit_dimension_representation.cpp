// Source for AP210 application object
//     limit_dimension_representation

// Precompiled include files
#include <StdAfx.h>

#include "limit_dimension_representation.h"

// Classes
#include <data_element.h>
#include <data_element.h>

limit_dimension_representation::limit_dimension_representation() {
   initialize();
   }
limit_dimension_representation::~limit_dimension_representation() {
   // Free string attributes
   }
// intialize data members
void limit_dimension_representation::initialize() {
   // Required attributes
   _upper_dimension_value = NULL;
   _lower_dimension_value = NULL;

   // Optional attributes
   }
// Runtime type identification
int limit_dimension_representation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = shape_dimension_representation::DynamicType(ID);
      }
   return result;
   }
limit_dimension_representation *limit_dimension_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<limit_dimension_representation *>(s);
      }
   return NULL;
   }
limit_dimension_representation *limit_dimension_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<limit_dimension_representation *>(s);
      }
   return NULL;
   }
// construction factory
limit_dimension_representation *limit_dimension_representation::Construct() {
   limit_dimension_representation *result = NULL;

   // create the limit_dimension_representation.
   result = new limit_dimension_representation();
   return result;
   }
bool limit_dimension_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: limit_dimension_representation\r\n");

   // Check for the existence of all required attributes
   if (_upper_dimension_value == NULL) {
      TRACE("ERROR: _upper_dimension_value a required attribute is NULL!\r\n");
      result = false;
      }
   if (_lower_dimension_value == NULL) {
      TRACE("ERROR: _lower_dimension_value a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (shape_dimension_representation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
