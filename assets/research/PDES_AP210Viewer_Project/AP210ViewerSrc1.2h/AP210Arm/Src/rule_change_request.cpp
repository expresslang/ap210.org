// Source for AP210 application object
//     rule_change_request

// Precompiled include files
#include <StdAfx.h>

#include "rule_change_request.h"

// Classes

rule_change_request::rule_change_request() {
   initialize();
   }
rule_change_request::~rule_change_request() {
   // Free string attributes
   if (_change_reason != NULL) {
      free(_change_reason);
     }
   }
// intialize data members
void rule_change_request::initialize() {
   // Required attributes
   _change_reason = NULL;

   // Optional attributes
   }
// Runtime type identification
int rule_change_request::DynamicType(int ID) {
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
rule_change_request *rule_change_request::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_change_request *>(s);
      }
   return NULL;
   }
rule_change_request *rule_change_request::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_change_request *>(s);
      }
   return NULL;
   }
// construction factory
rule_change_request *rule_change_request::Construct() {
   rule_change_request *result = NULL;

   // create the rule_change_request.
   result = new rule_change_request();
   return result;
   }
bool rule_change_request::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_change_request\r\n");

   // Check for the existence of all required attributes
   if (_change_reason == NULL) {
      TRACE("ERROR: _change_reason a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (rule_action::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
