// Source for AP210 application object
//     SetOfexternal_definition

// Precompiled include files
#include <StdAfx.h>

#include "SetOfexternal_definition.h"

// Classes
#include <external_definition.h>

SetOfexternal_definition::SetOfexternal_definition() {
   initialize();
   }
SetOfexternal_definition::~SetOfexternal_definition() {
   // Free string attributes
   }
// intialize data members
void SetOfexternal_definition::initialize() {
   // Required attributes
   _external_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfexternal_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfexternal_definition *SetOfexternal_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfexternal_definition *>(s);
      }
   return NULL;
   }
SetOfexternal_definition *SetOfexternal_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfexternal_definition *>(s);
      }
   return NULL;
   }
// construction factory
SetOfexternal_definition *SetOfexternal_definition::Construct() {
   SetOfexternal_definition *result = NULL;

   // create the SetOfexternal_definition.
   result = new SetOfexternal_definition();
   return result;
   }
bool SetOfexternal_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfexternal_definition\r\n");

   // Check for the existence of all required attributes
   if (_external_definition == NULL) {
      TRACE("ERROR: _external_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
