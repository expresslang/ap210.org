// Source for AP210 application object
//     SetOfassembly_joint

// Precompiled include files
#include <StdAfx.h>

#include "SetOfassembly_joint.h"

// Classes
#include <assembly_joint.h>

SetOfassembly_joint::SetOfassembly_joint() {
   initialize();
   }
SetOfassembly_joint::~SetOfassembly_joint() {
   // Free string attributes
   }
// intialize data members
void SetOfassembly_joint::initialize() {
   // Required attributes
   _assembly_joint = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfassembly_joint::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfassembly_joint *SetOfassembly_joint::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfassembly_joint *>(s);
      }
   return NULL;
   }
SetOfassembly_joint *SetOfassembly_joint::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfassembly_joint *>(s);
      }
   return NULL;
   }
// construction factory
SetOfassembly_joint *SetOfassembly_joint::Construct() {
   SetOfassembly_joint *result = NULL;

   // create the SetOfassembly_joint.
   result = new SetOfassembly_joint();
   return result;
   }
bool SetOfassembly_joint::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfassembly_joint\r\n");

   // Check for the existence of all required attributes
   if (_assembly_joint == NULL) {
      TRACE("ERROR: _assembly_joint a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
