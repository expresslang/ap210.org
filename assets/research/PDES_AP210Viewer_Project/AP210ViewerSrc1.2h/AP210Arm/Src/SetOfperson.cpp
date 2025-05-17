// Source for AP210 application object
//     SetOfperson

// Precompiled include files
#include <StdAfx.h>

#include "SetOfperson.h"

// Classes
#include <person.h>

SetOfperson::SetOfperson() {
   initialize();
   }
SetOfperson::~SetOfperson() {
   // Free string attributes
   }
// intialize data members
void SetOfperson::initialize() {
   // Required attributes
   _person = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfperson::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfperson *SetOfperson::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfperson *>(s);
      }
   return NULL;
   }
SetOfperson *SetOfperson::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfperson *>(s);
      }
   return NULL;
   }
// construction factory
SetOfperson *SetOfperson::Construct() {
   SetOfperson *result = NULL;

   // create the SetOfperson.
   result = new SetOfperson();
   return result;
   }
bool SetOfperson::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfperson\r\n");

   // Check for the existence of all required attributes
   if (_person == NULL) {
      TRACE("ERROR: _person a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
