// Source for AP210 application object
//     rule_justification

// Precompiled include files
#include <StdAfx.h>

#include "rule_justification.h"

// Classes
#include <rule_action.h>

rule_justification::rule_justification() {
   initialize();
   }
rule_justification::~rule_justification() {
   // Free string attributes
   if (_justification_rationale != NULL) {
      free(_justification_rationale);
     }
   }
// intialize data members
void rule_justification::initialize() {
   // Required attributes
   _justified_action = NULL;
   _justification_rationale = NULL;

   // Optional attributes
   }
// Runtime type identification
int rule_justification::DynamicType(int ID) {
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
rule_justification *rule_justification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_justification *>(s);
      }
   return NULL;
   }
rule_justification *rule_justification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_justification *>(s);
      }
   return NULL;
   }
// construction factory
rule_justification *rule_justification::Construct() {
   rule_justification *result = NULL;

   // create the rule_justification.
   result = new rule_justification();
   return result;
   }
bool rule_justification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_justification\r\n");

   // Check for the existence of all required attributes
   if (_justified_action == NULL) {
      TRACE("ERROR: _justified_action a required attribute is NULL!\r\n");
      result = false;
      }
   if (_justification_rationale == NULL) {
      TRACE("ERROR: _justification_rationale a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
