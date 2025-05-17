// Source for AP210 application object
//     directed_axis

// Precompiled include files
#include <StdAfx.h>

#include "directed_axis.h"

// Classes
#include <centre_axis.h>
#include <shape_element.h>
#include <shape_element.h>

directed_axis::directed_axis() {
   initialize();
   }
directed_axis::~directed_axis() {
   // Free string attributes
   }
// intialize data members
void directed_axis::initialize() {
   // Required attributes
   _axis_to_be_oriented = NULL;
   _start_shape_element = NULL;
   _end_shape_element = NULL;

   // Optional attributes
   }
// Runtime type identification
int directed_axis::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = non_feature_shape_element::DynamicType(ID);
      }
   return result;
   }
directed_axis *directed_axis::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<directed_axis *>(s);
      }
   return NULL;
   }
directed_axis *directed_axis::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<directed_axis *>(s);
      }
   return NULL;
   }
// construction factory
directed_axis *directed_axis::Construct() {
   directed_axis *result = NULL;

   // create the directed_axis.
   result = new directed_axis();
   return result;
   }
bool directed_axis::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: directed_axis\r\n");

   // Check for the existence of all required attributes
   if (_axis_to_be_oriented == NULL) {
      TRACE("ERROR: _axis_to_be_oriented a required attribute is NULL!\r\n");
      result = false;
      }
   if (_start_shape_element == NULL) {
      TRACE("ERROR: _start_shape_element a required attribute is NULL!\r\n");
      result = false;
      }
   if (_end_shape_element == NULL) {
      TRACE("ERROR: _end_shape_element a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (non_feature_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
