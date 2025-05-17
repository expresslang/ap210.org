// Source for AP210 application object
//     rule_submission

// Precompiled include files
#include <StdAfx.h>

#include "rule_submission.h"

// Classes

rule_submission::rule_submission() {
   initialize();
   }
rule_submission::~rule_submission() {
   // Free string attributes
   if (_submission_rationale != NULL) {
      free(_submission_rationale);
     }
   }
// intialize data members
void rule_submission::initialize() {
   // Required attributes
   _submission_rationale = NULL;

   // Optional attributes
   }
// Runtime type identification
int rule_submission::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = rule_action::DynamicType(ID);
      }
   return result;
   }
rule_submission *rule_submission::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_submission *>(s);
      }
   return NULL;
   }
rule_submission *rule_submission::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_submission *>(s);
      }
   return NULL;
   }
// construction factory
rule_submission *rule_submission::Construct() {
   rule_submission *result = NULL;

   // create the rule_submission.
   result = new rule_submission();
   return result;
   }
bool rule_submission::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_submission\r\n");

   // Check for the existence of all required attributes
   if (_submission_rationale == NULL) {
      TRACE("ERROR: _submission_rationale a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (rule_action::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
