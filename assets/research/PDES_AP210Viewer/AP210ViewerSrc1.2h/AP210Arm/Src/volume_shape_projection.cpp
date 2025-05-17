// Source for AP210 application object
//     volume_shape_projection

// Precompiled include files
#include <StdAfx.h>

#include "volume_shape_projection.h"

// Classes
#include <planar_projected_shape.h>
#include <bound_volume_shape.h>
#include <axis_placement.h>

volume_shape_projection::volume_shape_projection() {
   initialize();
   }
volume_shape_projection::~volume_shape_projection() {
   // Free string attributes
   }
// intialize data members
void volume_shape_projection::initialize() {
   // Required attributes
   _surface_projection = NULL;
   _projected_volume = NULL;
   _orientation_seating_plane = NULL;

   // Optional attributes
   }
// Runtime type identification
int volume_shape_projection::DynamicType(int ID) {
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
volume_shape_projection *volume_shape_projection::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<volume_shape_projection *>(s);
      }
   return NULL;
   }
volume_shape_projection *volume_shape_projection::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<volume_shape_projection *>(s);
      }
   return NULL;
   }
// construction factory
volume_shape_projection *volume_shape_projection::Construct() {
   volume_shape_projection *result = NULL;

   // create the volume_shape_projection.
   result = new volume_shape_projection();
   return result;
   }
bool volume_shape_projection::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: volume_shape_projection\r\n");

   // Check for the existence of all required attributes
   if (_surface_projection == NULL) {
      TRACE("ERROR: _surface_projection a required attribute is NULL!\r\n");
      result = false;
      }
   if (_projected_volume == NULL) {
      TRACE("ERROR: _projected_volume a required attribute is NULL!\r\n");
      result = false;
      }
   if (_orientation_seating_plane == NULL) {
      TRACE("ERROR: _orientation_seating_plane a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
