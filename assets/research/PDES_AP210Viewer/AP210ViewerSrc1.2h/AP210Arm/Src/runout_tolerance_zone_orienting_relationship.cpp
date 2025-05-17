// Source for AP210 application object
//     runout_tolerance_zone_orienting_relationship

// Precompiled include files
#include <StdAfx.h>

#include "runout_tolerance_zone_orienting_relationship.h"

// Classes
#include <tolerance_zone.h>
#include <directed_axis.h>

runout_tolerance_zone_orienting_relationship::runout_tolerance_zone_orienting_relationship() {
   initialize();
   }
runout_tolerance_zone_orienting_relationship::~runout_tolerance_zone_orienting_relationship() {
   // Free string attributes
   }
// intialize data members
void runout_tolerance_zone_orienting_relationship::initialize() {
   // Required attributes
   _oriented_zone = NULL;
   _orienting_axis = NULL;

   // Optional attributes
   }
// Runtime type identification
int runout_tolerance_zone_orienting_relationship::DynamicType(int ID) {
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
runout_tolerance_zone_orienting_relationship *runout_tolerance_zone_orienting_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<runout_tolerance_zone_orienting_relationship *>(s);
      }
   return NULL;
   }
runout_tolerance_zone_orienting_relationship *runout_tolerance_zone_orienting_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<runout_tolerance_zone_orienting_relationship *>(s);
      }
   return NULL;
   }
// construction factory
runout_tolerance_zone_orienting_relationship *runout_tolerance_zone_orienting_relationship::Construct() {
   runout_tolerance_zone_orienting_relationship *result = NULL;

   // create the runout_tolerance_zone_orienting_relationship.
   result = new runout_tolerance_zone_orienting_relationship();
   return result;
   }
bool runout_tolerance_zone_orienting_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: runout_tolerance_zone_orienting_relationship\r\n");

   // Check for the existence of all required attributes
   if (_oriented_zone == NULL) {
      TRACE("ERROR: _oriented_zone a required attribute is NULL!\r\n");
      result = false;
      }
   if (_orienting_axis == NULL) {
      TRACE("ERROR: _orienting_axis a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
