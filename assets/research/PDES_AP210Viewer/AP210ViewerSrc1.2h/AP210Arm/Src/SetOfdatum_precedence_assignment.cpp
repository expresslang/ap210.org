// Source for AP210 application object
//     SetOfdatum_precedence_assignment

// Precompiled include files
#include <StdAfx.h>

#include "SetOfdatum_precedence_assignment.h"

// Classes
#include <datum_precedence_assignment.h>

SetOfdatum_precedence_assignment::SetOfdatum_precedence_assignment() {
   initialize();
   }
SetOfdatum_precedence_assignment::~SetOfdatum_precedence_assignment() {
   // Free string attributes
   }
// intialize data members
void SetOfdatum_precedence_assignment::initialize() {
   // Required attributes
   _datum_precedence_assignment = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfdatum_precedence_assignment::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfdatum_precedence_assignment *SetOfdatum_precedence_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfdatum_precedence_assignment *>(s);
      }
   return NULL;
   }
SetOfdatum_precedence_assignment *SetOfdatum_precedence_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfdatum_precedence_assignment *>(s);
      }
   return NULL;
   }
// construction factory
SetOfdatum_precedence_assignment *SetOfdatum_precedence_assignment::Construct() {
   SetOfdatum_precedence_assignment *result = NULL;

   // create the SetOfdatum_precedence_assignment.
   result = new SetOfdatum_precedence_assignment();
   return result;
   }
bool SetOfdatum_precedence_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfdatum_precedence_assignment\r\n");

   // Check for the existence of all required attributes
   if (_datum_precedence_assignment == NULL) {
      TRACE("ERROR: _datum_precedence_assignment a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
