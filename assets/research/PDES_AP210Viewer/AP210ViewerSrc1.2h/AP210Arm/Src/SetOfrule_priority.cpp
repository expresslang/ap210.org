// Source for AP210 application object
//     SetOfrule_priority

// Precompiled include files
#include <StdAfx.h>

#include "SetOfrule_priority.h"

// Classes
#include <rule_priority.h>

SetOfrule_priority::SetOfrule_priority() {
   initialize();
   }
SetOfrule_priority::~SetOfrule_priority() {
   // Free string attributes
   }
// intialize data members
void SetOfrule_priority::initialize() {
   // Required attributes
   _rule_priority = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfrule_priority::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfrule_priority *SetOfrule_priority::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfrule_priority *>(s);
      }
   return NULL;
   }
SetOfrule_priority *SetOfrule_priority::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfrule_priority *>(s);
      }
   return NULL;
   }
// construction factory
SetOfrule_priority *SetOfrule_priority::Construct() {
   SetOfrule_priority *result = NULL;

   // create the SetOfrule_priority.
   result = new SetOfrule_priority();
   return result;
   }
bool SetOfrule_priority::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfrule_priority\r\n");

   // Check for the existence of all required attributes
   if (_rule_priority == NULL) {
      TRACE("ERROR: _rule_priority a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
