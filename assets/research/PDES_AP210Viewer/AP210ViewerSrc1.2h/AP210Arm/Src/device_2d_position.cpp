// Source for AP210 application object
//     device_2d_position

// Precompiled include files
#include <StdAfx.h>

#include "device_2d_position.h"

// Classes
#include <part_device.h>
#include <axis_placement_2d.h>
#include <physical_unit_planar_shape.h>
#include <physical_unit_planar_shape.h>

device_2d_position::device_2d_position() {
   initialize();
   }
device_2d_position::~device_2d_position() {
   // Free string attributes
   }
// intialize data members
void device_2d_position::initialize() {
   // Required attributes
   _placed_device = NULL;
   _transformation = NULL;
   _part_shape = NULL;
   _device_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int device_2d_position::DynamicType(int ID) {
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
device_2d_position *device_2d_position::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<device_2d_position *>(s);
      }
   return NULL;
   }
device_2d_position *device_2d_position::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<device_2d_position *>(s);
      }
   return NULL;
   }
// construction factory
device_2d_position *device_2d_position::Construct() {
   device_2d_position *result = NULL;

   // create the device_2d_position.
   result = new device_2d_position();
   return result;
   }
bool device_2d_position::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: device_2d_position\r\n");

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
