// Source for AP210 application object
//     SetOfdimensional_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "SetOfdimensional_characteristic.h"

// Classes
#include <dimensional_characteristic.h>

SetOfdimensional_characteristic::SetOfdimensional_characteristic() {
   initialize();
   }
SetOfdimensional_characteristic::~SetOfdimensional_characteristic() {
   // Free string attributes
   }
// intialize data members
void SetOfdimensional_characteristic::initialize() {
   // Required attributes
   _dimensional_characteristic = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfdimensional_characteristic::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfdimensional_characteristic *SetOfdimensional_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfdimensional_characteristic *>(s);
      }
   return NULL;
   }
SetOfdimensional_characteristic *SetOfdimensional_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfdimensional_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
SetOfdimensional_characteristic *SetOfdimensional_characteristic::Construct() {
   SetOfdimensional_characteristic *result = NULL;

   // create the SetOfdimensional_characteristic.
   result = new SetOfdimensional_characteristic();
   return result;
   }
bool SetOfdimensional_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfdimensional_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_dimensional_characteristic == NULL) {
      TRACE("ERROR: _dimensional_characteristic a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
