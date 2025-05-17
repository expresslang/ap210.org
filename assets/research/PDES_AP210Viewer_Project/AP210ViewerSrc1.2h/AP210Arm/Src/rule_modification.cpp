// Source for AP210 application object
//     rule_modification

// Precompiled include files
#include <StdAfx.h>

#include "rule_modification.h"

// Classes
#include <rule_change_request.h>

rule_modification::rule_modification() {
   initialize();
   }
rule_modification::~rule_modification() {
   // Free string attributes
   }
// intialize data members
void rule_modification::initialize() {
   // Required attributes
   _modification_rationale = NULL;

   // Optional attributes
   }
// Runtime type identification
int rule_modification::DynamicType(int ID) {
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
rule_modification *rule_modification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_modification *>(s);
      }
   return NULL;
   }
rule_modification *rule_modification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_modification *>(s);
      }
   return NULL;
   }
// construction factory
rule_modification *rule_modification::Construct() {
   rule_modification *result = NULL;

   // create the rule_modification.
   result = new rule_modification();
   return result;
   }
bool rule_modification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_modification\r\n");

   // Check for the existence of all required attributes
   if (_modification_rationale == NULL) {
      TRACE("ERROR: _modification_rationale a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (rule_action::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
