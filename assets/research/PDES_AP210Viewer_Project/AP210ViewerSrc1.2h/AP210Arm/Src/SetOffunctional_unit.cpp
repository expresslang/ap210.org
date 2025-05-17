// Source for AP210 application object
//     SetOffunctional_unit

// Precompiled include files
#include <StdAfx.h>

#include "SetOffunctional_unit.h"

// Classes
#include <functional_unit.h>

SetOffunctional_unit::SetOffunctional_unit() {
   initialize();
   }
SetOffunctional_unit::~SetOffunctional_unit() {
   // Free string attributes
   }
// intialize data members
void SetOffunctional_unit::initialize() {
   // Required attributes
   _functional_unit = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOffunctional_unit::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOffunctional_unit *SetOffunctional_unit::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOffunctional_unit *>(s);
      }
   return NULL;
   }
SetOffunctional_unit *SetOffunctional_unit::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOffunctional_unit *>(s);
      }
   return NULL;
   }
// construction factory
SetOffunctional_unit *SetOffunctional_unit::Construct() {
   SetOffunctional_unit *result = NULL;

   // create the SetOffunctional_unit.
   result = new SetOffunctional_unit();
   return result;
   }
bool SetOffunctional_unit::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOffunctional_unit\r\n");

   // Check for the existence of all required attributes
   if (_functional_unit == NULL) {
      TRACE("ERROR: _functional_unit a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
