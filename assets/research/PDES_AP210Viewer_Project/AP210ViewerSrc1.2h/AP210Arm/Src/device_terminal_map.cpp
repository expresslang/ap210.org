// Source for AP210 application object
//     device_terminal_map

// Precompiled include files
#include <StdAfx.h>

#include "device_terminal_map.h"

// Classes
#include <packaged_part_terminal.h>
#include <part_device_terminal.h>

device_terminal_map::device_terminal_map() {
   initialize();
   }
device_terminal_map::~device_terminal_map() {
   // Free string attributes
   }
// intialize data members
void device_terminal_map::initialize() {
   // Required attributes
   _target_terminal = NULL;
   _mapped_device_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int device_terminal_map::DynamicType(int ID) {
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
device_terminal_map *device_terminal_map::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<device_terminal_map *>(s);
      }
   return NULL;
   }
device_terminal_map *device_terminal_map::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<device_terminal_map *>(s);
      }
   return NULL;
   }
// construction factory
device_terminal_map *device_terminal_map::Construct() {
   device_terminal_map *result = NULL;

   // create the device_terminal_map.
   result = new device_terminal_map();
   return result;
   }
bool device_terminal_map::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: device_terminal_map\r\n");

   // Check for the existence of all required attributes
   if (_target_terminal == NULL) {
      TRACE("ERROR: _target_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_mapped_device_terminal == NULL) {
      TRACE("ERROR: _mapped_device_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
