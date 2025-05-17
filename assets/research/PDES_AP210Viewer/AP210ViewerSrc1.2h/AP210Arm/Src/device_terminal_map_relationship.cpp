// Source for AP210 application object
//     device_terminal_map_relationship

// Precompiled include files
#include <StdAfx.h>

#include "device_terminal_map_relationship.h"

// Classes
#include <device_terminal_map.h>
#include <device_terminal_map.h>

device_terminal_map_relationship::device_terminal_map_relationship() {
   initialize();
   }
device_terminal_map_relationship::~device_terminal_map_relationship() {
   // Free string attributes
   }
// intialize data members
void device_terminal_map_relationship::initialize() {
   // Required attributes
   _related_device_terminal_map = NULL;
   _relating_device_terminal_map = NULL;

   // Optional attributes
   }
// Runtime type identification
int device_terminal_map_relationship::DynamicType(int ID) {
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
device_terminal_map_relationship *device_terminal_map_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<device_terminal_map_relationship *>(s);
      }
   return NULL;
   }
device_terminal_map_relationship *device_terminal_map_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<device_terminal_map_relationship *>(s);
      }
   return NULL;
   }
// construction factory
device_terminal_map_relationship *device_terminal_map_relationship::Construct() {
   device_terminal_map_relationship *result = NULL;

   // create the device_terminal_map_relationship.
   result = new device_terminal_map_relationship();
   return result;
   }
bool device_terminal_map_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: device_terminal_map_relationship\r\n");

   // Check for the existence of all required attributes
   if (_related_device_terminal_map == NULL) {
      TRACE("ERROR: _related_device_terminal_map a required attribute is NULL!\r\n");
      result = false;
      }
   if (_relating_device_terminal_map == NULL) {
      TRACE("ERROR: _relating_device_terminal_map a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
