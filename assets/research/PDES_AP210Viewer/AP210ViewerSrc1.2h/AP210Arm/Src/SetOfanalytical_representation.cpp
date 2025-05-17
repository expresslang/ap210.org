// Source for AP210 application object
//     SetOfanalytical_representation

// Precompiled include files
#include <StdAfx.h>

#include "SetOfanalytical_representation.h"

// Classes
#include <analytical_representation.h>

SetOfanalytical_representation::SetOfanalytical_representation() {
   initialize();
   }
SetOfanalytical_representation::~SetOfanalytical_representation() {
   // Free string attributes
   }
// intialize data members
void SetOfanalytical_representation::initialize() {
   // Required attributes
   _analytical_representation = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfanalytical_representation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfanalytical_representation *SetOfanalytical_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfanalytical_representation *>(s);
      }
   return NULL;
   }
SetOfanalytical_representation *SetOfanalytical_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfanalytical_representation *>(s);
      }
   return NULL;
   }
// construction factory
SetOfanalytical_representation *SetOfanalytical_representation::Construct() {
   SetOfanalytical_representation *result = NULL;

   // create the SetOfanalytical_representation.
   result = new SetOfanalytical_representation();
   return result;
   }
bool SetOfanalytical_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfanalytical_representation\r\n");

   // Check for the existence of all required attributes
   if (_analytical_representation == NULL) {
      TRACE("ERROR: _analytical_representation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
