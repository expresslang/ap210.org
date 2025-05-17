// Source for AP210 application object
//     SetOfcorrelated_or_independent

// Precompiled include files
#include <StdAfx.h>

#include "SetOfcorrelated_or_independent.h"

// Classes

SetOfcorrelated_or_independent::SetOfcorrelated_or_independent() {
   initialize();
   }
SetOfcorrelated_or_independent::~SetOfcorrelated_or_independent() {
   // Free string attributes
   }
// intialize data members
void SetOfcorrelated_or_independent::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOfcorrelated_or_independent::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfcorrelated_or_independent *SetOfcorrelated_or_independent::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfcorrelated_or_independent *>(s);
      }
   return NULL;
   }
SetOfcorrelated_or_independent *SetOfcorrelated_or_independent::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfcorrelated_or_independent *>(s);
      }
   return NULL;
   }
// construction factory
SetOfcorrelated_or_independent *SetOfcorrelated_or_independent::Construct() {
   SetOfcorrelated_or_independent *result = NULL;

   // create the SetOfcorrelated_or_independent.
   result = new SetOfcorrelated_or_independent();
   return result;
   }
bool SetOfcorrelated_or_independent::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfcorrelated_or_independent\r\n");

   // Check for the existence of all required attributes
   if (_correlated_or_independent == NULL) {
      TRACE("ERROR: _correlated_or_independent a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
