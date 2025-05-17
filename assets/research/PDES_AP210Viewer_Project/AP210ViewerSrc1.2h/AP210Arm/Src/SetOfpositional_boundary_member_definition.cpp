// Source for AP210 application object
//     SetOfpositional_boundary_member_definition

// Precompiled include files
#include <StdAfx.h>

#include "SetOfpositional_boundary_member_definition.h"

// Classes
#include <positional_boundary_member_definition.h>

SetOfpositional_boundary_member_definition::SetOfpositional_boundary_member_definition() {
   initialize();
   }
SetOfpositional_boundary_member_definition::~SetOfpositional_boundary_member_definition() {
   // Free string attributes
   }
// intialize data members
void SetOfpositional_boundary_member_definition::initialize() {
   // Required attributes
   _positional_boundary_member_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfpositional_boundary_member_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfpositional_boundary_member_definition *SetOfpositional_boundary_member_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfpositional_boundary_member_definition *>(s);
      }
   return NULL;
   }
SetOfpositional_boundary_member_definition *SetOfpositional_boundary_member_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfpositional_boundary_member_definition *>(s);
      }
   return NULL;
   }
// construction factory
SetOfpositional_boundary_member_definition *SetOfpositional_boundary_member_definition::Construct() {
   SetOfpositional_boundary_member_definition *result = NULL;

   // create the SetOfpositional_boundary_member_definition.
   result = new SetOfpositional_boundary_member_definition();
   return result;
   }
bool SetOfpositional_boundary_member_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfpositional_boundary_member_definition\r\n");

   // Check for the existence of all required attributes
   if (_positional_boundary_member_definition == NULL) {
      TRACE("ERROR: _positional_boundary_member_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
