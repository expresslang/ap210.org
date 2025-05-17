// Source for AP210 application object
//     SetOfee_text

// Precompiled include files
#include <StdAfx.h>

#include "SetOfee_text.h"

// Classes
#include <ee_text.h>

SetOfee_text::SetOfee_text() {
   initialize();
   }
SetOfee_text::~SetOfee_text() {
   // Free string attributes
   }
// intialize data members
void SetOfee_text::initialize() {
   // Required attributes
   _ee_text = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfee_text::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfee_text *SetOfee_text::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfee_text *>(s);
      }
   return NULL;
   }
SetOfee_text *SetOfee_text::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfee_text *>(s);
      }
   return NULL;
   }
// construction factory
SetOfee_text *SetOfee_text::Construct() {
   SetOfee_text *result = NULL;

   // create the SetOfee_text.
   result = new SetOfee_text();
   return result;
   }
bool SetOfee_text::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfee_text\r\n");

   // Check for the existence of all required attributes
   if (_ee_text == NULL) {
      TRACE("ERROR: _ee_text a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
