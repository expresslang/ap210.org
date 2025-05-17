// Source for AP210 application object
//     SetOfcomponent_terminal

// Precompiled include files
#include <StdAfx.h>

#include "SetOfcomponent_terminal.h"

// Classes
#include <component_terminal.h>

SetOfcomponent_terminal::SetOfcomponent_terminal() {
   initialize();
   }
SetOfcomponent_terminal::~SetOfcomponent_terminal() {
   // Free string attributes
   }
// intialize data members
void SetOfcomponent_terminal::initialize() {
   // Required attributes
   _component_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfcomponent_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfcomponent_terminal *SetOfcomponent_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfcomponent_terminal *>(s);
      }
   return NULL;
   }
SetOfcomponent_terminal *SetOfcomponent_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfcomponent_terminal *>(s);
      }
   return NULL;
   }
// construction factory
SetOfcomponent_terminal *SetOfcomponent_terminal::Construct() {
   SetOfcomponent_terminal *result = NULL;

   // create the SetOfcomponent_terminal.
   result = new SetOfcomponent_terminal();
   return result;
   }
bool SetOfcomponent_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfcomponent_terminal\r\n");

   // Check for the existence of all required attributes
   if (_component_terminal == NULL) {
      TRACE("ERROR: _component_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
