// Source for AP210 application object
//     SetOfpositional_boundary_member

// Precompiled include files
#include <StdAfx.h>

#include "SetOfpositional_boundary_member.h"

// Classes
#include <positional_boundary_member.h>

SetOfpositional_boundary_member::SetOfpositional_boundary_member() {
   initialize();
   }
SetOfpositional_boundary_member::~SetOfpositional_boundary_member() {
   // Free string attributes
   }
// intialize data members
void SetOfpositional_boundary_member::initialize() {
   // Required attributes
   _positional_boundary_member = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfpositional_boundary_member::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfpositional_boundary_member *SetOfpositional_boundary_member::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfpositional_boundary_member *>(s);
      }
   return NULL;
   }
SetOfpositional_boundary_member *SetOfpositional_boundary_member::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfpositional_boundary_member *>(s);
      }
   return NULL;
   }
// construction factory
SetOfpositional_boundary_member *SetOfpositional_boundary_member::Construct() {
   SetOfpositional_boundary_member *result = NULL;

   // create the SetOfpositional_boundary_member.
   result = new SetOfpositional_boundary_member();
   return result;
   }
bool SetOfpositional_boundary_member::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfpositional_boundary_member\r\n");

   // Check for the existence of all required attributes
   if (_positional_boundary_member == NULL) {
      TRACE("ERROR: _positional_boundary_member a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
