// Source for AP210 application object
//     printed_part_template_join_terminal

// Precompiled include files
#include <StdAfx.h>

#include "printed_part_template_join_terminal.h"

// Classes

printed_part_template_join_terminal::printed_part_template_join_terminal() {
   initialize();
   }
printed_part_template_join_terminal::~printed_part_template_join_terminal() {
   // Free string attributes
   }
// intialize data members
void printed_part_template_join_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int printed_part_template_join_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = printed_part_template_terminal::DynamicType(ID);
      }
   return result;
   }
printed_part_template_join_terminal *printed_part_template_join_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_part_template_join_terminal *>(s);
      }
   return NULL;
   }
printed_part_template_join_terminal *printed_part_template_join_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_part_template_join_terminal *>(s);
      }
   return NULL;
   }
// construction factory
printed_part_template_join_terminal *printed_part_template_join_terminal::Construct() {
   printed_part_template_join_terminal *result = NULL;

   // create the printed_part_template_join_terminal.
   result = new printed_part_template_join_terminal();
   return result;
   }
bool printed_part_template_join_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_part_template_join_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (printed_part_template_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
