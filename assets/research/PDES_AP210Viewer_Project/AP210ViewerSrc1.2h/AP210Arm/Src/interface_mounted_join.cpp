// Source for AP210 application object
//     interface_mounted_join

// Precompiled include files
#include <StdAfx.h>

#include "interface_mounted_join.h"

// Classes
#include <component_interface_terminal.h>
#include <component_terminal.h>

interface_mounted_join::interface_mounted_join() {
   initialize();
   }
interface_mounted_join::~interface_mounted_join() {
   // Free string attributes
   }
// intialize data members
void interface_mounted_join::initialize() {
   // Required attributes
   _connection_to_interconnect_module_component = NULL;
   _access_to_interface_mounted_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int interface_mounted_join::DynamicType(int ID) {
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
interface_mounted_join *interface_mounted_join::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interface_mounted_join *>(s);
      }
   return NULL;
   }
interface_mounted_join *interface_mounted_join::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interface_mounted_join *>(s);
      }
   return NULL;
   }
// construction factory
interface_mounted_join *interface_mounted_join::Construct() {
   interface_mounted_join *result = NULL;

   // create the interface_mounted_join.
   result = new interface_mounted_join();
   return result;
   }
bool interface_mounted_join::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interface_mounted_join\r\n");

   // Check for the existence of all required attributes
   if (_connection_to_interconnect_module_component == NULL) {
      TRACE("ERROR: _connection_to_interconnect_module_component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_access_to_interface_mounted_component == NULL) {
      TRACE("ERROR: _access_to_interface_mounted_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
