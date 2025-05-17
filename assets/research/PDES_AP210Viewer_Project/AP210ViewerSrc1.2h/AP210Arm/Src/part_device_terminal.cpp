// Source for AP210 application object
//     part_device_terminal

// Precompiled include files
#include <StdAfx.h>

#include "part_device_terminal.h"

// Classes
#include <minimally_defined_bare_die_terminal.h>
#include <part_device.h>

part_device_terminal::part_device_terminal() {
   initialize();
   }
part_device_terminal::~part_device_terminal() {
   // Free string attributes
   }
// intialize data members
void part_device_terminal::initialize() {
   // Required attributes
   _used_bare_die_terminal = NULL;
   _terminated_device = NULL;

   // Optional attributes
   }
// Runtime type identification
int part_device_terminal::DynamicType(int ID) {
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
part_device_terminal *part_device_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_device_terminal *>(s);
      }
   return NULL;
   }
part_device_terminal *part_device_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_device_terminal *>(s);
      }
   return NULL;
   }
// construction factory
part_device_terminal *part_device_terminal::Construct() {
   part_device_terminal *result = NULL;

   // create the part_device_terminal.
   result = new part_device_terminal();
   return result;
   }
bool part_device_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_device_terminal\r\n");

   // Check for the existence of all required attributes
   if (_used_bare_die_terminal == NULL) {
      TRACE("ERROR: _used_bare_die_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   if (_terminated_device == NULL) {
      TRACE("ERROR: _terminated_device a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
