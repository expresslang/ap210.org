// Source for AP210 application object
//     guided_wave_bare_die_terminal

// Precompiled include files
#include <StdAfx.h>

#include "guided_wave_bare_die_terminal.h"

// Classes

guided_wave_bare_die_terminal::guided_wave_bare_die_terminal() {
   initialize();
   }
guided_wave_bare_die_terminal::~guided_wave_bare_die_terminal() {
   // Free string attributes
   }
// intialize data members
void guided_wave_bare_die_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int guided_wave_bare_die_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = minimally_defined_bare_die_terminal::DynamicType(ID);
      }
   return result;
   }
guided_wave_bare_die_terminal *guided_wave_bare_die_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<guided_wave_bare_die_terminal *>(s);
      }
   return NULL;
   }
guided_wave_bare_die_terminal *guided_wave_bare_die_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<guided_wave_bare_die_terminal *>(s);
      }
   return NULL;
   }
// construction factory
guided_wave_bare_die_terminal *guided_wave_bare_die_terminal::Construct() {
   guided_wave_bare_die_terminal *result = NULL;

   // create the guided_wave_bare_die_terminal.
   result = new guided_wave_bare_die_terminal();
   return result;
   }
bool guided_wave_bare_die_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: guided_wave_bare_die_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (minimally_defined_bare_die_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
