// Source for AP210 application object
//     bare_die

// Precompiled include files
#include <StdAfx.h>

#include "bare_die.h"

// Classes
#include <cartesian_point.h>
#include <length_data_element.h>
#include <cartesian_point.h>
#include <seating_plane.h>
#include <functional_unit_usage_view.h>

bare_die::bare_die() {
   initialize();
   }
bare_die::~bare_die() {
   // Free string attributes
   }
// intialize data members
void bare_die::initialize() {
   // Required attributes
   _die_seating_plane = NULL;
   _implemented_function = NULL;

   // Optional attributes
   _least_material_condition_centroid_location = NULL;
   _maximum_height_above_seating_plane = NULL;
   _maximum_material_condition_centroid_location = NULL;
   }
// Runtime type identification
int bare_die::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = physical_unit_usage_view::DynamicType(ID);
      }
   return result;
   }
bare_die *bare_die::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bare_die *>(s);
      }
   return NULL;
   }
bare_die *bare_die::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bare_die *>(s);
      }
   return NULL;
   }
// construction factory
bare_die *bare_die::Construct() {
   bare_die *result = NULL;

   // create the bare_die.
   result = new bare_die();
   return result;
   }
bool bare_die::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bare_die\r\n");

   // Check for the existence of all required attributes
   if (_die_seating_plane == NULL) {
      TRACE("ERROR: _die_seating_plane a required attribute is NULL!\r\n");
      result = false;
      }
   if (_implemented_function == NULL) {
      TRACE("ERROR: _implemented_function a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (physical_unit_usage_view::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
