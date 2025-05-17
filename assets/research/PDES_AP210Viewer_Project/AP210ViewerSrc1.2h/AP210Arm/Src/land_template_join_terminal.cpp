// Source for AP210 application object
//     land_template_join_terminal

// Precompiled include files
#include <StdAfx.h>

#include "land_template_join_terminal.h"

// Classes

land_template_join_terminal::land_template_join_terminal() {
   initialize();
   }
land_template_join_terminal::~land_template_join_terminal() {
   // Free string attributes
   }
// intialize data members
void land_template_join_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int land_template_join_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = land_template_terminal::DynamicType(ID);
      }
   return result;
   }
land_template_join_terminal *land_template_join_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<land_template_join_terminal *>(s);
      }
   return NULL;
   }
land_template_join_terminal *land_template_join_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<land_template_join_terminal *>(s);
      }
   return NULL;
   }
// construction factory
land_template_join_terminal *land_template_join_terminal::Construct() {
   land_template_join_terminal *result = NULL;

   // create the land_template_join_terminal.
   result = new land_template_join_terminal();
   return result;
   }
bool land_template_join_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: land_template_join_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (land_template_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
