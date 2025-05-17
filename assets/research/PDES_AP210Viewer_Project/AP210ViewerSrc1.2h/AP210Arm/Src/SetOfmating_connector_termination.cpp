// Source for AP210 application object
//     SetOfmating_connector_termination

// Precompiled include files
#include <StdAfx.h>

#include "SetOfmating_connector_termination.h"

// Classes
#include <mating_connector_termination.h>

SetOfmating_connector_termination::SetOfmating_connector_termination() {
   initialize();
   }
SetOfmating_connector_termination::~SetOfmating_connector_termination() {
   // Free string attributes
   }
// intialize data members
void SetOfmating_connector_termination::initialize() {
   // Required attributes
   _mating_connector_termination = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfmating_connector_termination::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfmating_connector_termination *SetOfmating_connector_termination::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfmating_connector_termination *>(s);
      }
   return NULL;
   }
SetOfmating_connector_termination *SetOfmating_connector_termination::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfmating_connector_termination *>(s);
      }
   return NULL;
   }
// construction factory
SetOfmating_connector_termination *SetOfmating_connector_termination::Construct() {
   SetOfmating_connector_termination *result = NULL;

   // create the SetOfmating_connector_termination.
   result = new SetOfmating_connector_termination();
   return result;
   }
bool SetOfmating_connector_termination::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfmating_connector_termination\r\n");

   // Check for the existence of all required attributes
   if (_mating_connector_termination == NULL) {
      TRACE("ERROR: _mating_connector_termination a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
