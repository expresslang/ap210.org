// Source for AP210 application object
//     rule_set_group

// Precompiled include files
#include <StdAfx.h>

#include "rule_set_group.h"

// Classes

rule_set_group::rule_set_group() {
   initialize();
   }
rule_set_group::~rule_set_group() {
   // Free string attributes
   }
// intialize data members
void rule_set_group::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int rule_set_group::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = rule_set::DynamicType(ID);
      }
   return result;
   }
rule_set_group *rule_set_group::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_set_group *>(s);
      }
   return NULL;
   }
rule_set_group *rule_set_group::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_set_group *>(s);
      }
   return NULL;
   }
// construction factory
rule_set_group *rule_set_group::Construct() {
   rule_set_group *result = NULL;

   // create the rule_set_group.
   result = new rule_set_group();
   return result;
   }
bool rule_set_group::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_set_group\r\n");

   // Check for the existence of all required attributes
   if (_elements == NULL) {
      TRACE("ERROR: _elements a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (rule_set::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
