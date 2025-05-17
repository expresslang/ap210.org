// Source for AP210 application object
//     SetOfparameter_assignment

// Precompiled include files
#include <StdAfx.h>

#include "SetOfparameter_assignment.h"

// Classes
#include <parameter_assignment.h>

SetOfparameter_assignment::SetOfparameter_assignment() {
   initialize();
   }
SetOfparameter_assignment::~SetOfparameter_assignment() {
   // Free string attributes
   }
// intialize data members
void SetOfparameter_assignment::initialize() {
   // Required attributes
   _parameter_assignment = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfparameter_assignment::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfparameter_assignment *SetOfparameter_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfparameter_assignment *>(s);
      }
   return NULL;
   }
SetOfparameter_assignment *SetOfparameter_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfparameter_assignment *>(s);
      }
   return NULL;
   }
// construction factory
SetOfparameter_assignment *SetOfparameter_assignment::Construct() {
   SetOfparameter_assignment *result = NULL;

   // create the SetOfparameter_assignment.
   result = new SetOfparameter_assignment();
   return result;
   }
bool SetOfparameter_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfparameter_assignment\r\n");

   // Check for the existence of all required attributes
   if (_parameter_assignment == NULL) {
      TRACE("ERROR: _parameter_assignment a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
