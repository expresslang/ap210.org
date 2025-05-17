// Source for AP210 application object
//     runout_tolerance_zone_definition_with_specified_angle

// Precompiled include files
#include <StdAfx.h>

#include "runout_tolerance_zone_definition_with_specified_angle.h"

// Classes
#include <runout_zone_orientation.h>

runout_tolerance_zone_definition_with_specified_angle::runout_tolerance_zone_definition_with_specified_angle() {
   initialize();
   }
runout_tolerance_zone_definition_with_specified_angle::~runout_tolerance_zone_definition_with_specified_angle() {
   // Free string attributes
   }
// intialize data members
void runout_tolerance_zone_definition_with_specified_angle::initialize() {
   // Required attributes
   _runout_orientation = NULL;

   // Optional attributes
   }
// Runtime type identification
int runout_tolerance_zone_definition_with_specified_angle::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = tolerance_zone_definition::DynamicType(ID);
      }
   return result;
   }
runout_tolerance_zone_definition_with_specified_angle *runout_tolerance_zone_definition_with_specified_angle::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<runout_tolerance_zone_definition_with_specified_angle *>(s);
      }
   return NULL;
   }
runout_tolerance_zone_definition_with_specified_angle *runout_tolerance_zone_definition_with_specified_angle::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<runout_tolerance_zone_definition_with_specified_angle *>(s);
      }
   return NULL;
   }
// construction factory
runout_tolerance_zone_definition_with_specified_angle *runout_tolerance_zone_definition_with_specified_angle::Construct() {
   runout_tolerance_zone_definition_with_specified_angle *result = NULL;

   // create the runout_tolerance_zone_definition_with_specified_angle.
   result = new runout_tolerance_zone_definition_with_specified_angle();
   return result;
   }
bool runout_tolerance_zone_definition_with_specified_angle::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: runout_tolerance_zone_definition_with_specified_angle\r\n");

   // Check for the existence of all required attributes
   if (_runout_orientation == NULL) {
      TRACE("ERROR: _runout_orientation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (tolerance_zone_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
