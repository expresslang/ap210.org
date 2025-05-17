// Source for AP210 application object
//     participant_date_and_time_assignment

// Precompiled include files
#include <StdAfx.h>

#include "participant_date_and_time_assignment.h"

// Classes
#include <person_and_organization.h>
#include <date_and_time.h>

participant_date_and_time_assignment::participant_date_and_time_assignment() {
   initialize();
   }
participant_date_and_time_assignment::~participant_date_and_time_assignment() {
   // Free string attributes
   }
// intialize data members
void participant_date_and_time_assignment::initialize() {
   // Required attributes
   _action_participant = NULL;
   _action_date_and_time = NULL;

   // Optional attributes
   }
// Runtime type identification
int participant_date_and_time_assignment::DynamicType(int ID) {
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
participant_date_and_time_assignment *participant_date_and_time_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<participant_date_and_time_assignment *>(s);
      }
   return NULL;
   }
participant_date_and_time_assignment *participant_date_and_time_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<participant_date_and_time_assignment *>(s);
      }
   return NULL;
   }
// construction factory
participant_date_and_time_assignment *participant_date_and_time_assignment::Construct() {
   participant_date_and_time_assignment *result = NULL;

   // create the participant_date_and_time_assignment.
   result = new participant_date_and_time_assignment();
   return result;
   }
bool participant_date_and_time_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: participant_date_and_time_assignment\r\n");

   // Check for the existence of all required attributes
   if (_action_participant == NULL) {
      TRACE("ERROR: _action_participant a required attribute is NULL!\r\n");
      result = false;
      }
   if (_action_date_and_time == NULL) {
      TRACE("ERROR: _action_date_and_time a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
