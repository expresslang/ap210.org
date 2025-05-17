// Source for AP210 application object
//     rule_supersedence

// Precompiled include files
#include <StdAfx.h>

#include "rule_supersedence.h"

// Classes
#include <ee_rule_version.h>

rule_supersedence::rule_supersedence() {
   initialize();
   }
rule_supersedence::~rule_supersedence() {
   // Free string attributes
   }
// intialize data members
void rule_supersedence::initialize() {
   // Required attributes
   _superseded_rule = NULL;

   // Optional attributes
   }
// Runtime type identification
int rule_supersedence::DynamicType(int ID) {
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
rule_supersedence *rule_supersedence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_supersedence *>(s);
      }
   return NULL;
   }
rule_supersedence *rule_supersedence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_supersedence *>(s);
      }
   return NULL;
   }
// construction factory
rule_supersedence *rule_supersedence::Construct() {
   rule_supersedence *result = NULL;

   // create the rule_supersedence.
   result = new rule_supersedence();
   return result;
   }
bool rule_supersedence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_supersedence\r\n");

   // Check for the existence of all required attributes
   if (_superseded_rule == NULL) {
      TRACE("ERROR: _superseded_rule a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (rule_action::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
