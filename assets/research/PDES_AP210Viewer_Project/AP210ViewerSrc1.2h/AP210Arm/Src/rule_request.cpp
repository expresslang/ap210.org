// Source for AP210 application object
//     rule_request

// Precompiled include files
#include <StdAfx.h>

#include "rule_request.h"

// Classes

rule_request::rule_request() {
   initialize();
   }
rule_request::~rule_request() {
   // Free string attributes
   }
// intialize data members
void rule_request::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int rule_request::DynamicType(int ID) {
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
rule_request *rule_request::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_request *>(s);
      }
   return NULL;
   }
rule_request *rule_request::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_request *>(s);
      }
   return NULL;
   }
// construction factory
rule_request *rule_request::Construct() {
   rule_request *result = NULL;

   // create the rule_request.
   result = new rule_request();
   return result;
   }
bool rule_request::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_request\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (rule_action::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
