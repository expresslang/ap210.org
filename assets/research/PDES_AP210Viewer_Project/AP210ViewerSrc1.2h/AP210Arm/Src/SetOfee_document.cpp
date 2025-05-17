// Source for AP210 application object
//     SetOfee_document

// Precompiled include files
#include <StdAfx.h>

#include "SetOfee_document.h"

// Classes
#include <ee_document.h>

SetOfee_document::SetOfee_document() {
   initialize();
   }
SetOfee_document::~SetOfee_document() {
   // Free string attributes
   }
// intialize data members
void SetOfee_document::initialize() {
   // Required attributes
   _ee_document = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfee_document::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfee_document *SetOfee_document::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfee_document *>(s);
      }
   return NULL;
   }
SetOfee_document *SetOfee_document::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfee_document *>(s);
      }
   return NULL;
   }
// construction factory
SetOfee_document *SetOfee_document::Construct() {
   SetOfee_document *result = NULL;

   // create the SetOfee_document.
   result = new SetOfee_document();
   return result;
   }
bool SetOfee_document::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfee_document\r\n");

   // Check for the existence of all required attributes
   if (_ee_document == NULL) {
      TRACE("ERROR: _ee_document a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
