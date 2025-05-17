// Source for AP210 application object
//     SetOfcharacteristic

// Precompiled include files
#include <StdAfx.h>

#include "SetOfcharacteristic.h"

// Classes
#include <characteristic.h>

SetOfcharacteristic::SetOfcharacteristic() {
   initialize();
   }
SetOfcharacteristic::~SetOfcharacteristic() {
   // Free string attributes
   }
// intialize data members
void SetOfcharacteristic::initialize() {
   // Required attributes
   _characteristic = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfcharacteristic::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfcharacteristic *SetOfcharacteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfcharacteristic *>(s);
      }
   return NULL;
   }
SetOfcharacteristic *SetOfcharacteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfcharacteristic *>(s);
      }
   return NULL;
   }
// construction factory
SetOfcharacteristic *SetOfcharacteristic::Construct() {
   SetOfcharacteristic *result = NULL;

   // create the SetOfcharacteristic.
   result = new SetOfcharacteristic();
   return result;
   }
bool SetOfcharacteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfcharacteristic\r\n");

   // Check for the existence of all required attributes
   if (_characteristic == NULL) {
      TRACE("ERROR: _characteristic a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
