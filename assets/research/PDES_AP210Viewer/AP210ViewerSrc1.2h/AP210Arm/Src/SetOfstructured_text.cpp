// Source for AP210 application object
//     SetOfstructured_text

// Precompiled include files
#include <StdAfx.h>

#include "SetOfstructured_text.h"

// Classes
#include <structured_text.h>

SetOfstructured_text::SetOfstructured_text() {
   initialize();
   }
SetOfstructured_text::~SetOfstructured_text() {
   // Free string attributes
   }
// intialize data members
void SetOfstructured_text::initialize() {
   // Required attributes
   _structured_text = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfstructured_text::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfstructured_text *SetOfstructured_text::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfstructured_text *>(s);
      }
   return NULL;
   }
SetOfstructured_text *SetOfstructured_text::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfstructured_text *>(s);
      }
   return NULL;
   }
// construction factory
SetOfstructured_text *SetOfstructured_text::Construct() {
   SetOfstructured_text *result = NULL;

   // create the SetOfstructured_text.
   result = new SetOfstructured_text();
   return result;
   }
bool SetOfstructured_text::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfstructured_text\r\n");

   // Check for the existence of all required attributes
   if (_structured_text == NULL) {
      TRACE("ERROR: _structured_text a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
