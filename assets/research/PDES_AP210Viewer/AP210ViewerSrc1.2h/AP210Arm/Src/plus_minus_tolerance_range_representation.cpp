// Source for AP210 application object
//     plus_minus_tolerance_range_representation

// Precompiled include files
#include <StdAfx.h>

#include "plus_minus_tolerance_range_representation.h"

// Classes
#include <data_element.h>
#include <data_element.h>
#include <data_element.h>

plus_minus_tolerance_range_representation::plus_minus_tolerance_range_representation() {
   initialize();
   }
plus_minus_tolerance_range_representation::~plus_minus_tolerance_range_representation() {
   // Free string attributes
   }
// intialize data members
void plus_minus_tolerance_range_representation::initialize() {
   // Required attributes
   _basic_dimension_value = NULL;
   _upper_deviation = NULL;
   _lower_deviation = NULL;

   // Optional attributes
   }
// Runtime type identification
int plus_minus_tolerance_range_representation::DynamicType(int ID) {
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
plus_minus_tolerance_range_representation *plus_minus_tolerance_range_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<plus_minus_tolerance_range_representation *>(s);
      }
   return NULL;
   }
plus_minus_tolerance_range_representation *plus_minus_tolerance_range_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<plus_minus_tolerance_range_representation *>(s);
      }
   return NULL;
   }
// construction factory
plus_minus_tolerance_range_representation *plus_minus_tolerance_range_representation::Construct() {
   plus_minus_tolerance_range_representation *result = NULL;

   // create the plus_minus_tolerance_range_representation.
   result = new plus_minus_tolerance_range_representation();
   return result;
   }
bool plus_minus_tolerance_range_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: plus_minus_tolerance_range_representation\r\n");

   // Check for the existence of all required attributes
   if (_basic_dimension_value == NULL) {
      TRACE("ERROR: _basic_dimension_value a required attribute is NULL!\r\n");
      result = false;
      }
   if (_upper_deviation == NULL) {
      TRACE("ERROR: _upper_deviation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_lower_deviation == NULL) {
      TRACE("ERROR: _lower_deviation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (shape_dimension_representation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
