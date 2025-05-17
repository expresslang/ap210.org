// Source for AP210 application object
//     SetOfee_requirement_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "SetOfee_requirement_occurrence.h"

// Classes
#include <ee_requirement_occurrence.h>

SetOfee_requirement_occurrence::SetOfee_requirement_occurrence() {
   initialize();
   }
SetOfee_requirement_occurrence::~SetOfee_requirement_occurrence() {
   // Free string attributes
   }
// intialize data members
void SetOfee_requirement_occurrence::initialize() {
   // Required attributes
   _ee_requirement_occurrence = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfee_requirement_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfee_requirement_occurrence *SetOfee_requirement_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfee_requirement_occurrence *>(s);
      }
   return NULL;
   }
SetOfee_requirement_occurrence *SetOfee_requirement_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfee_requirement_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
SetOfee_requirement_occurrence *SetOfee_requirement_occurrence::Construct() {
   SetOfee_requirement_occurrence *result = NULL;

   // create the SetOfee_requirement_occurrence.
   result = new SetOfee_requirement_occurrence();
   return result;
   }
bool SetOfee_requirement_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfee_requirement_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_ee_requirement_occurrence == NULL) {
      TRACE("ERROR: _ee_requirement_occurrence a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
