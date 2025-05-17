// Source for AP210 application object
//     rule_adoption

// Precompiled include files
#include <StdAfx.h>

#include "rule_adoption.h"

// Classes

rule_adoption::rule_adoption() {
   initialize();
   }
rule_adoption::~rule_adoption() {
   // Free string attributes
   }
// intialize data members
void rule_adoption::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int rule_adoption::DynamicType(int ID) {
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
rule_adoption *rule_adoption::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_adoption *>(s);
      }
   return NULL;
   }
rule_adoption *rule_adoption::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_adoption *>(s);
      }
   return NULL;
   }
// construction factory
rule_adoption *rule_adoption::Construct() {
   rule_adoption *result = NULL;

   // create the rule_adoption.
   result = new rule_adoption();
   return result;
   }
bool rule_adoption::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_adoption\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (rule_action::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
