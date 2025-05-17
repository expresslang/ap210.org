// Source for AP210 application object
//     SetOfprinted_part_template_terminal

// Precompiled include files
#include <StdAfx.h>

#include "SetOfprinted_part_template_terminal.h"

// Classes
#include <printed_part_template_terminal.h>

SetOfprinted_part_template_terminal::SetOfprinted_part_template_terminal() {
   initialize();
   }
SetOfprinted_part_template_terminal::~SetOfprinted_part_template_terminal() {
   // Free string attributes
   }
// intialize data members
void SetOfprinted_part_template_terminal::initialize() {
   // Required attributes
   _printed_part_template_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfprinted_part_template_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfprinted_part_template_terminal *SetOfprinted_part_template_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfprinted_part_template_terminal *>(s);
      }
   return NULL;
   }
SetOfprinted_part_template_terminal *SetOfprinted_part_template_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfprinted_part_template_terminal *>(s);
      }
   return NULL;
   }
// construction factory
SetOfprinted_part_template_terminal *SetOfprinted_part_template_terminal::Construct() {
   SetOfprinted_part_template_terminal *result = NULL;

   // create the SetOfprinted_part_template_terminal.
   result = new SetOfprinted_part_template_terminal();
   return result;
   }
bool SetOfprinted_part_template_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfprinted_part_template_terminal\r\n");

   // Check for the existence of all required attributes
   if (_printed_part_template_terminal == NULL) {
      TRACE("ERROR: _printed_part_template_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
