// Source for AP210 application object
//     package

// Precompiled include files
#include <StdAfx.h>

#include "package.h"

// Classes
#include <seating_plane.h>
#include <cartesian_point.h>
#include <cartesian_point.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>

package::package() {
   initialize();
   }
package::~package() {
   // Free string attributes
   }
// intialize data members
void package::initialize() {
   // Required attributes
   _package_seating_plane = NULL;
   _maximum_body_height_above_seating_plane = NULL;

   // Optional attributes
   _least_material_condition_centroid_location = NULL;
   _maximum_material_condition_centroid_location = NULL;
   _maximum_body_height_below_seating_plane = NULL;
   _maximum_body_clearance_above_seating_plane = NULL;
   _maximum_body_clearance_below_seating_plane = NULL;
   _minimum_body_clearance_above_seating_plane = NULL;
   _minimum_body_clearance_below_seating_plane = NULL;
   _maximum_lead_length_below_seating_plane = NULL;
   _least_lead_length_below_seating_plane = NULL;
   }
// Runtime type identification
int package::DynamicType(int ID) {
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
package *package::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<package *>(s);
      }
   return NULL;
   }
package *package::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<package *>(s);
      }
   return NULL;
   }
// construction factory
package *package::Construct() {
   package *result = NULL;

   // create the package.
   result = new package();
   return result;
   }
bool package::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: package\r\n");

   // Check for the existence of all required attributes
   if (_case_style == NULL) {
      TRACE("ERROR: _case_style a required attribute is NULL!\r\n");
      result = false;
      }
   if (_package_seating_plane == NULL) {
      TRACE("ERROR: _package_seating_plane a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_body_height_above_seating_plane == NULL) {
      TRACE("ERROR: _maximum_body_height_above_seating_plane a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (physical_unit_usage_view::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
