// Source for AP210 application object
//     rule_set

// Precompiled include files
#include <StdAfx.h>

#include "rule_set.h"

// Classes

rule_set::rule_set() {
   initialize();
   }
rule_set::~rule_set() {
   // Free string attributes
   if (_identifier != NULL) {
      free(_identifier);
     }
   if (_purpose != NULL) {
      free(_purpose);
     }
   }
// intialize data members
void rule_set::initialize() {
   // Required attributes
   _identifier = NULL;
   _purpose = NULL;

   // Optional attributes
   }
// Runtime type identification
int rule_set::DynamicType(int ID) {
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
rule_set *rule_set::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<rule_set *>(s);
      }
   return NULL;
   }
rule_set *rule_set::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<rule_set *>(s);
      }
   return NULL;
   }
// construction factory
rule_set *rule_set::Construct() {
   rule_set *result = NULL;

   // create the rule_set.
   result = new rule_set();
   return result;
   }
bool rule_set::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: rule_set\r\n");

   // Check for the existence of all required attributes
   if (_rule_priority_member == NULL) {
      TRACE("ERROR: _rule_priority_member a required attribute is NULL!\r\n");
      result = false;
      }
   if (_identifier == NULL) {
      TRACE("ERROR: _identifier a required attribute is NULL!\r\n");
      result = false;
      }
   if (_purpose == NULL) {
      TRACE("ERROR: _purpose a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
