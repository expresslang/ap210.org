// Source for AP210 application object
//     packaged_part_join_terminal

// Precompiled include files
#include <StdAfx.h>

#include "packaged_part_join_terminal.h"

// Classes

packaged_part_join_terminal::packaged_part_join_terminal() {
   initialize();
   }
packaged_part_join_terminal::~packaged_part_join_terminal() {
   // Free string attributes
   }
// intialize data members
void packaged_part_join_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int packaged_part_join_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = packaged_part_terminal::DynamicType(ID);
      }
   return result;
   }
packaged_part_join_terminal *packaged_part_join_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<packaged_part_join_terminal *>(s);
      }
   return NULL;
   }
packaged_part_join_terminal *packaged_part_join_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<packaged_part_join_terminal *>(s);
      }
   return NULL;
   }
// construction factory
packaged_part_join_terminal *packaged_part_join_terminal::Construct() {
   packaged_part_join_terminal *result = NULL;

   // create the packaged_part_join_terminal.
   result = new packaged_part_join_terminal();
   return result;
   }
bool packaged_part_join_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: packaged_part_join_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (packaged_part_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
