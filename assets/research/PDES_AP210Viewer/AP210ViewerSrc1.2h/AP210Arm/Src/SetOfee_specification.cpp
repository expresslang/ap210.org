// Source for AP210 application object
//     SetOfee_specification

// Precompiled include files
#include <StdAfx.h>

#include "SetOfee_specification.h"

// Classes
#include <ee_specification.h>

SetOfee_specification::SetOfee_specification() {
   initialize();
   }
SetOfee_specification::~SetOfee_specification() {
   // Free string attributes
   }
// intialize data members
void SetOfee_specification::initialize() {
   // Required attributes
   _ee_specification = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfee_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfee_specification *SetOfee_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfee_specification *>(s);
      }
   return NULL;
   }
SetOfee_specification *SetOfee_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfee_specification *>(s);
      }
   return NULL;
   }
// construction factory
SetOfee_specification *SetOfee_specification::Construct() {
   SetOfee_specification *result = NULL;

   // create the SetOfee_specification.
   result = new SetOfee_specification();
   return result;
   }
bool SetOfee_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfee_specification\r\n");

   // Check for the existence of all required attributes
   if (_ee_specification == NULL) {
      TRACE("ERROR: _ee_specification a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
