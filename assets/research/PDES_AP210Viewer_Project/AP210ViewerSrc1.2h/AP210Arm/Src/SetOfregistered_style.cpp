// Source for AP210 application object
//     SetOfregistered_style

// Precompiled include files
#include <StdAfx.h>

#include "SetOfregistered_style.h"

// Classes
#include <registered_style.h>

SetOfregistered_style::SetOfregistered_style() {
   initialize();
   }
SetOfregistered_style::~SetOfregistered_style() {
   // Free string attributes
   }
// intialize data members
void SetOfregistered_style::initialize() {
   // Required attributes
   _registered_style = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfregistered_style::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfregistered_style *SetOfregistered_style::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfregistered_style *>(s);
      }
   return NULL;
   }
SetOfregistered_style *SetOfregistered_style::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfregistered_style *>(s);
      }
   return NULL;
   }
// construction factory
SetOfregistered_style *SetOfregistered_style::Construct() {
   SetOfregistered_style *result = NULL;

   // create the SetOfregistered_style.
   result = new SetOfregistered_style();
   return result;
   }
bool SetOfregistered_style::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfregistered_style\r\n");

   // Check for the existence of all required attributes
   if (_registered_style == NULL) {
      TRACE("ERROR: _registered_style a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
