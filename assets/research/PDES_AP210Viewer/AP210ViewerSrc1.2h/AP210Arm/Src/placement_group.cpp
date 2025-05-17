// Source for AP210 application object
//     placement_group

// Precompiled include files
#include <StdAfx.h>

#include "placement_group.h"

// Classes

placement_group::placement_group() {
   initialize();
   }
placement_group::~placement_group() {
   // Free string attributes
   if (_design_specific_usage != NULL) {
      free(_design_specific_usage);
     }
   }
// intialize data members
void placement_group::initialize() {
   // Required attributes
   _design_specific_usage = NULL;

   // Optional attributes
   }
// Runtime type identification
int placement_group::DynamicType(int ID) {
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
placement_group *placement_group::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<placement_group *>(s);
      }
   return NULL;
   }
placement_group *placement_group::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<placement_group *>(s);
      }
   return NULL;
   }
// construction factory
placement_group *placement_group::Construct() {
   placement_group *result = NULL;

   // create the placement_group.
   result = new placement_group();
   return result;
   }
bool placement_group::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: placement_group\r\n");

   // Check for the existence of all required attributes
   if (_design_specific_usage == NULL) {
      TRACE("ERROR: _design_specific_usage a required attribute is NULL!\r\n");
      result = false;
      }
   if (_requirement == NULL) {
      TRACE("ERROR: _requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
