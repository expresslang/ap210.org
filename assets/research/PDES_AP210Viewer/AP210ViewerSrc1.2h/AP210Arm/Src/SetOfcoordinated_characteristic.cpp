// Source for AP210 application object
//     SetOfcoordinated_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "SetOfcoordinated_characteristic.h"

// Classes
#include <coordinated_characteristic.h>

SetOfcoordinated_characteristic::SetOfcoordinated_characteristic() {
   initialize();
   }
SetOfcoordinated_characteristic::~SetOfcoordinated_characteristic() {
   // Free string attributes
   }
// intialize data members
void SetOfcoordinated_characteristic::initialize() {
   // Required attributes
   _coordinated_characteristic = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfcoordinated_characteristic::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfcoordinated_characteristic *SetOfcoordinated_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfcoordinated_characteristic *>(s);
      }
   return NULL;
   }
SetOfcoordinated_characteristic *SetOfcoordinated_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfcoordinated_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
SetOfcoordinated_characteristic *SetOfcoordinated_characteristic::Construct() {
   SetOfcoordinated_characteristic *result = NULL;

   // create the SetOfcoordinated_characteristic.
   result = new SetOfcoordinated_characteristic();
   return result;
   }
bool SetOfcoordinated_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfcoordinated_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_coordinated_characteristic == NULL) {
      TRACE("ERROR: _coordinated_characteristic a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
