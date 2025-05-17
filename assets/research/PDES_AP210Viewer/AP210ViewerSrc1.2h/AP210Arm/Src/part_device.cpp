// Source for AP210 application object
//     part_device

// Precompiled include files
#include <StdAfx.h>

#include "part_device.h"

// Classes
#include <packaged_part.h>
#include <bare_die.h>
#include <ee_material.h>

part_device::part_device() {
   initialize();
   }
part_device::~part_device() {
   // Free string attributes
   if (_item_identification != NULL) {
      free(_item_identification);
     }
   }
// intialize data members
void part_device::initialize() {
   // Required attributes
   _defined_packaged_part = NULL;
   _included_device = NULL;
   _item_identification = NULL;

   // Optional attributes
   _bonding_agent = NULL;
   }
// Runtime type identification
int part_device::DynamicType(int ID) {
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
part_device *part_device::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_device *>(s);
      }
   return NULL;
   }
part_device *part_device::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_device *>(s);
      }
   return NULL;
   }
// construction factory
part_device *part_device::Construct() {
   part_device *result = NULL;

   // create the part_device.
   result = new part_device();
   return result;
   }
bool part_device::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_device\r\n");

   // Check for the existence of all required attributes
   if (_defined_packaged_part == NULL) {
      TRACE("ERROR: _defined_packaged_part a required attribute is NULL!\r\n");
      result = false;
      }
   if (_included_device == NULL) {
      TRACE("ERROR: _included_device a required attribute is NULL!\r\n");
      result = false;
      }
   if (_item_identification == NULL) {
      TRACE("ERROR: _item_identification a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
