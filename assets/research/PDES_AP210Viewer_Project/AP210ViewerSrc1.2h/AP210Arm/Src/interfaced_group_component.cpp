// Source for AP210 application object
//     interfaced_group_component

// Precompiled include files
#include <StdAfx.h>

#include "interfaced_group_component.h"

// Classes

interfaced_group_component::interfaced_group_component() {
   initialize();
   }
interfaced_group_component::~interfaced_group_component() {
   // Free string attributes
   }
// intialize data members
void interfaced_group_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interfaced_group_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_group_component::DynamicType(ID);
      }
   return result;
   }
interfaced_group_component *interfaced_group_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interfaced_group_component *>(s);
      }
   return NULL;
   }
interfaced_group_component *interfaced_group_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interfaced_group_component *>(s);
      }
   return NULL;
   }
// construction factory
interfaced_group_component *interfaced_group_component::Construct() {
   interfaced_group_component *result = NULL;

   // create the interfaced_group_component.
   result = new interfaced_group_component();
   return result;
   }
bool interfaced_group_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interfaced_group_component\r\n");

   // Check for the existence of all required attributes
   if (_group_interface_component == NULL) {
      TRACE("ERROR: _group_interface_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (assembly_group_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
