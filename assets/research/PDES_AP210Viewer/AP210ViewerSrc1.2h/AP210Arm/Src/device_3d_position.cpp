// Source for AP210 application object
//     device_3d_position

// Precompiled include files
#include <StdAfx.h>

#include "device_3d_position.h"

// Classes
#include <part_device.h>
#include <axis_placement_3d.h>
#include <physical_unit_3d_shape.h>
#include <physical_unit_3d_shape.h>

device_3d_position::device_3d_position() {
   initialize();
   }
device_3d_position::~device_3d_position() {
   // Free string attributes
   }
// intialize data members
void device_3d_position::initialize() {
   // Required attributes
   _placed_device = NULL;
   _transformation = NULL;
   _part_shape = NULL;
   _device_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int device_3d_position::DynamicType(int ID) {
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
device_3d_position *device_3d_position::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<device_3d_position *>(s);
      }
   return NULL;
   }
device_3d_position *device_3d_position::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<device_3d_position *>(s);
      }
   return NULL;
   }
// construction factory
device_3d_position *device_3d_position::Construct() {
   device_3d_position *result = NULL;

   // create the device_3d_position.
   result = new device_3d_position();
   return result;
   }
bool device_3d_position::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: device_3d_position\r\n");

   // Check for the existence of all required attributes
   if (_placed_device == NULL) {
      TRACE("ERROR: _placed_device a required attribute is NULL!\r\n");
      result = false;
      }
   if (_transformation == NULL) {
      TRACE("ERROR: _transformation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_part_shape == NULL) {
      TRACE("ERROR: _part_shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_device_shape == NULL) {
      TRACE("ERROR: _device_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
