// Source for AP210 application object
//     rule_action

// Precompiled include files
#include <StdAfx.h>

#include "rule_action.h"

// Classes
#include <participant_date_and_time_assignment.h>
#include <ee_rule_version.h>

rule_action::rule_action() {
   initialize();
   }
rule_action::~rule_action() {
   // Free string attributes
   }
// intialize data members
void rule_action::initialize() {
   // Required attributes
   _subject_action_assignment = NULL;
   _subject_rule = NULL;

   // Optional attributes
   }
// Runtime type identification
int rule_action::DynamicType(int ID) {
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
rule_action *rule_action::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_action *>(s);
      }
   return NULL;
   }
rule_action *rule_action::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_action *>(s);
      }
   return NULL;
   }
// construction factory
rule_action *rule_action::Construct() {
   rule_action *result = NULL;

   // create the rule_action.
   result = new rule_action();
   return result;
   }
bool rule_action::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_action\r\n");

   // Check for the existence of all required attributes
   if (_subject_action_assignment == NULL) {
      TRACE("ERROR: _subject_action_assignment a required attribute is NULL!\r\n");
      result = false;
      }
   if (_subject_rule == NULL) {
      TRACE("ERROR: _subject_rule a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
