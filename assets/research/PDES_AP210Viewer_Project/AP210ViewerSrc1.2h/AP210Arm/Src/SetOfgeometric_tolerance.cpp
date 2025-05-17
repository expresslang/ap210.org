// Source for AP210 application object
//     SetOfgeometric_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "SetOfgeometric_tolerance.h"

// Classes
#include <geometric_tolerance.h>

SetOfgeometric_tolerance::SetOfgeometric_tolerance() {
   initialize();
   }
SetOfgeometric_tolerance::~SetOfgeometric_tolerance() {
   // Free string attributes
   }
// intialize data members
void SetOfgeometric_tolerance::initialize() {
   // Required attributes
   _geometric_tolerance = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfgeometric_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfgeometric_tolerance *SetOfgeometric_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfgeometric_tolerance *>(s);
      }
   return NULL;
   }
SetOfgeometric_tolerance *SetOfgeometric_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfgeometric_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
SetOfgeometric_tolerance *SetOfgeometric_tolerance::Construct() {
   SetOfgeometric_tolerance *result = NULL;

   // create the SetOfgeometric_tolerance.
   result = new SetOfgeometric_tolerance();
   return result;
   }
bool SetOfgeometric_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfgeometric_tolerance\r\n");

   // Check for the existence of all required attributes
   if (_geometric_tolerance == NULL) {
      TRACE("ERROR: _geometric_tolerance a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
