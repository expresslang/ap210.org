// Source for AP210 application object
//     rule_expiration

// Precompiled include files
#include <StdAfx.h>

#include "rule_expiration.h"

// Classes

rule_expiration::rule_expiration() {
   initialize();
   }
rule_expiration::~rule_expiration() {
   // Free string attributes
   if (_expiration_rationale != NULL) {
      free(_expiration_rationale);
     }
   }
// intialize data members
void rule_expiration::initialize() {
   // Required attributes
   _expiration_rationale = NULL;

   // Optional attributes
   }
// Runtime type identification
int rule_expiration::DynamicType(int ID) {
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
rule_expiration *rule_expiration::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_expiration *>(s);
      }
   return NULL;
   }
rule_expiration *rule_expiration::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_expiration *>(s);
      }
   return NULL;
   }
// construction factory
rule_expiration *rule_expiration::Construct() {
   rule_expiration *result = NULL;

   // create the rule_expiration.
   result = new rule_expiration();
   return result;
   }
bool rule_expiration::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_expiration\r\n");

   // Check for the existence of all required attributes
   if (_expiration_rationale == NULL) {
      TRACE("ERROR: _expiration_rationale a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (rule_action::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
