// Source for AP210 application object
//     SetOfpart_terminal

// Precompiled include files
#include <StdAfx.h>

#include "SetOfpart_terminal.h"

// Classes
#include <part_terminal.h>

SetOfpart_terminal::SetOfpart_terminal() {
   initialize();
   }
SetOfpart_terminal::~SetOfpart_terminal() {
   // Free string attributes
   }
// intialize data members
void SetOfpart_terminal::initialize() {
   // Required attributes
   _part_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfpart_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfpart_terminal *SetOfpart_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfpart_terminal *>(s);
      }
   return NULL;
   }
SetOfpart_terminal *SetOfpart_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfpart_terminal *>(s);
      }
   return NULL;
   }
// construction factory
SetOfpart_terminal *SetOfpart_terminal::Construct() {
   SetOfpart_terminal *result = NULL;

   // create the SetOfpart_terminal.
   result = new SetOfpart_terminal();
   return result;
   }
bool SetOfpart_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfpart_terminal\r\n");

   // Check for the existence of all required attributes
   if (_part_terminal == NULL) {
      TRACE("ERROR: _part_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
