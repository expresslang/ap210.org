// Source for AP210 application object
//     runout_zone_orientation

// Precompiled include files
#include <StdAfx.h>

#include "runout_zone_orientation.h"

// Classes
#include <runout_tolerance_zone_orienting_relationship.h>
#include <angle_data_element.h>

runout_zone_orientation::runout_zone_orientation() {
   initialize();
   }
runout_zone_orientation::~runout_zone_orientation() {
   // Free string attributes
   }
// intialize data members
void runout_zone_orientation::initialize() {
   // Required attributes
   _oriented_relationship = NULL;
   _semi_angle_value = NULL;

   // Optional attributes
   }
// Runtime type identification
int runout_zone_orientation::DynamicType(int ID) {
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
runout_zone_orientation *runout_zone_orientation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<runout_zone_orientation *>(s);
      }
   return NULL;
   }
runout_zone_orientation *runout_zone_orientation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<runout_zone_orientation *>(s);
      }
   return NULL;
   }
// construction factory
runout_zone_orientation *runout_zone_orientation::Construct() {
   runout_zone_orientation *result = NULL;

   // create the runout_zone_orientation.
   result = new runout_zone_orientation();
   return result;
   }
bool runout_zone_orientation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: runout_zone_orientation\r\n");

   // Check for the existence of all required attributes
   if (_oriented_relationship == NULL) {
      TRACE("ERROR: _oriented_relationship a required attribute is NULL!\r\n");
      result = false;
      }
   if (_semi_angle_value == NULL) {
      TRACE("ERROR: _semi_angle_value a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
