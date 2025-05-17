// Source for AP210 application object
//     SetOfee_rule_simple_clause

// Precompiled include files
#include <StdAfx.h>

#include "SetOfee_rule_simple_clause.h"

// Classes
#include <ee_rule_simple_clause.h>

SetOfee_rule_simple_clause::SetOfee_rule_simple_clause() {
   initialize();
   }
SetOfee_rule_simple_clause::~SetOfee_rule_simple_clause() {
   // Free string attributes
   }
// intialize data members
void SetOfee_rule_simple_clause::initialize() {
   // Required attributes
   _ee_rule_simple_clause = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfee_rule_simple_clause::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfee_rule_simple_clause *SetOfee_rule_simple_clause::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfee_rule_simple_clause *>(s);
      }
   return NULL;
   }
SetOfee_rule_simple_clause *SetOfee_rule_simple_clause::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfee_rule_simple_clause *>(s);
      }
   return NULL;
   }
// construction factory
SetOfee_rule_simple_clause *SetOfee_rule_simple_clause::Construct() {
   SetOfee_rule_simple_clause *result = NULL;

   // create the SetOfee_rule_simple_clause.
   result = new SetOfee_rule_simple_clause();
   return result;
   }
bool SetOfee_rule_simple_clause::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfee_rule_simple_clause\r\n");

   // Check for the existence of all required attributes
   if (_ee_rule_simple_clause == NULL) {
      TRACE("ERROR: _ee_rule_simple_clause a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
