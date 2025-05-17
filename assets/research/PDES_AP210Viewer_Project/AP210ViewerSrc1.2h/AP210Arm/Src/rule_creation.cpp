// Source for AP210 application object
//     rule_creation

// Precompiled include files
#include <StdAfx.h>

#include "rule_creation.h"

// Classes

rule_creation::rule_creation() {
   initialize();
   }
rule_creation::~rule_creation() {
   // Free string attributes
   }
// intialize data members
void rule_creation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int rule_creation::DynamicType(int ID) {
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
rule_creation *rule_creation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_creation *>(s);
      }
   return NULL;
   }
rule_creation *rule_creation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_creation *>(s);
      }
   return NULL;
   }
// construction factory
rule_creation *rule_creation::Construct() {
   rule_creation *result = NULL;

   // create the rule_creation.
   result = new rule_creation();
   return result;
   }
bool rule_creation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_creation\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (rule_action::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
