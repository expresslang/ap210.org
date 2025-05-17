// Source for AP210 application object
//     direction_element

// Precompiled include files
#include <StdAfx.h>

#include "direction_element.h"

// Classes
#include <datum_based_direction_vector.h>
#include <angle_data_element.h>
#include <datum_plane.h>
#include <datum_based_direction_vector.h>

direction_element::direction_element() {
   initialize();
   }
direction_element::~direction_element() {
   // Free string attributes
   }
// intialize data members
void direction_element::initialize() {
   // Required attributes
   _direction = NULL;
   _angle_value = NULL;
   _base_datum_plane = NULL;
   _direction_of_half_datum_plane = NULL;

   // Optional attributes
   }
// Runtime type identification
int direction_element::DynamicType(int ID) {
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
direction_element *direction_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<direction_element *>(s);
      }
   return NULL;
   }
direction_element *direction_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<direction_element *>(s);
      }
   return NULL;
   }
// construction factory
direction_element *direction_element::Construct() {
   direction_element *result = NULL;

   // create the direction_element.
   result = new direction_element();
   return result;
   }
bool direction_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: direction_element\r\n");

   // Check for the existence of all required attributes
   if (_direction == NULL) {
      TRACE("ERROR: _direction a required attribute is NULL!\r\n");
      result = false;
      }
   if (_angle_value == NULL) {
      TRACE("ERROR: _angle_value a required attribute is NULL!\r\n");
      result = false;
      }
   if (_base_datum_plane == NULL) {
      TRACE("ERROR: _base_datum_plane a required attribute is NULL!\r\n");
      result = false;
      }
   if (_direction_of_half_datum_plane == NULL) {
      TRACE("ERROR: _direction_of_half_datum_plane a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
