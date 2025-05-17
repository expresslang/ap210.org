// Source for AP210 application object
//     rule_rejection

// Precompiled include files
#include <StdAfx.h>

#include "rule_rejection.h"

// Classes

rule_rejection::rule_rejection() {
   initialize();
   }
rule_rejection::~rule_rejection() {
   // Free string attributes
   if (_rejection_reason != NULL) {
      free(_rejection_reason);
     }
   }
// intialize data members
void rule_rejection::initialize() {
   // Required attributes
   _rejection_reason = NULL;

   // Optional attributes
   }
// Runtime type identification
int rule_rejection::DynamicType(int ID) {
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
rule_rejection *rule_rejection::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_rejection *>(s);
      }
   return NULL;
   }
rule_rejection *rule_rejection::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_rejection *>(s);
      }
   return NULL;
   }
// construction factory
rule_rejection *rule_rejection::Construct() {
   rule_rejection *result = NULL;

   // create the rule_rejection.
   result = new rule_rejection();
   return result;
   }
bool rule_rejection::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_rejection\r\n");

   // Check for the existence of all required attributes
   if (_rejection_reason == NULL) {
      TRACE("ERROR: _rejection_reason a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (rule_action::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
