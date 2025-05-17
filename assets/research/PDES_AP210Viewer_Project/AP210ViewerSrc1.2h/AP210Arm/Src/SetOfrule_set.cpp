// Source for AP210 application object
//     SetOfrule_set

// Precompiled include files
#include <StdAfx.h>

#include "SetOfrule_set.h"

// Classes
#include <rule_set.h>

SetOfrule_set::SetOfrule_set() {
   initialize();
   }
SetOfrule_set::~SetOfrule_set() {
   // Free string attributes
   }
// intialize data members
void SetOfrule_set::initialize() {
   // Required attributes
   _rule_set = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfrule_set::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfrule_set *SetOfrule_set::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfrule_set *>(s);
      }
   return NULL;
   }
SetOfrule_set *SetOfrule_set::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfrule_set *>(s);
      }
   return NULL;
   }
// construction factory
SetOfrule_set *SetOfrule_set::Construct() {
   SetOfrule_set *result = NULL;

   // create the SetOfrule_set.
   result = new SetOfrule_set();
   return result;
   }
bool SetOfrule_set::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfrule_set\r\n");

   // Check for the existence of all required attributes
   if (_rule_set == NULL) {
      TRACE("ERROR: _rule_set a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
