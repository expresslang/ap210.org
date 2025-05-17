// Source for AP210 application object
//     SetOftermination_or_junction

// Precompiled include files
#include <StdAfx.h>

#include "SetOftermination_or_junction.h"

// Classes

SetOftermination_or_junction::SetOftermination_or_junction() {
   initialize();
   }
SetOftermination_or_junction::~SetOftermination_or_junction() {
   // Free string attributes
   }
// intialize data members
void SetOftermination_or_junction::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOftermination_or_junction::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOftermination_or_junction *SetOftermination_or_junction::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOftermination_or_junction *>(s);
      }
   return NULL;
   }
SetOftermination_or_junction *SetOftermination_or_junction::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOftermination_or_junction *>(s);
      }
   return NULL;
   }
// construction factory
SetOftermination_or_junction *SetOftermination_or_junction::Construct() {
   SetOftermination_or_junction *result = NULL;

   // create the SetOftermination_or_junction.
   result = new SetOftermination_or_junction();
   return result;
   }
bool SetOftermination_or_junction::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOftermination_or_junction\r\n");

   // Check for the existence of all required attributes
   if (_termination_or_junction == NULL) {
      TRACE("ERROR: _termination_or_junction a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
