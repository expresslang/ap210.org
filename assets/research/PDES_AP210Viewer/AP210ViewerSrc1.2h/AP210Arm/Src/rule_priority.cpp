// Source for AP210 application object
//     rule_priority

// Precompiled include files
#include <StdAfx.h>

#include "rule_priority.h"

// Classes
#include <ee_rule_version.h>

rule_priority::rule_priority() {
   initialize();
   }
rule_priority::~rule_priority() {
   // Free string attributes
   }
// intialize data members
void rule_priority::initialize() {
   // Required attributes
   _prioritized_rule = NULL;

   // Optional attributes
   }
// Runtime type identification
int rule_priority::DynamicType(int ID) {
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
rule_priority *rule_priority::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_priority *>(s);
      }
   return NULL;
   }
rule_priority *rule_priority::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_priority *>(s);
      }
   return NULL;
   }
// construction factory
rule_priority *rule_priority::Construct() {
   rule_priority *result = NULL;

   // create the rule_priority.
   result = new rule_priority();
   return result;
   }
bool rule_priority::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_priority\r\n");

   // Check for the existence of all required attributes
   if (_priority == NULL) {
      TRACE("ERROR: _priority a required attribute is NULL!\r\n");
      result = false;
      }
   if (_prioritized_rule == NULL) {
      TRACE("ERROR: _prioritized_rule a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
