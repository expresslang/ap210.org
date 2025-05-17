// Source for AP210 application object
//     packaged_part_terminal

// Precompiled include files
#include <StdAfx.h>

#include "packaged_part_terminal.h"

// Classes

packaged_part_terminal::packaged_part_terminal() {
   initialize();
   }
packaged_part_terminal::~packaged_part_terminal() {
   // Free string attributes
   }
// intialize data members
void packaged_part_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int packaged_part_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_terminal::DynamicType(ID);
      }
   return result;
   }
packaged_part_terminal *packaged_part_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<packaged_part_terminal *>(s);
      }
   return NULL;
   }
packaged_part_terminal *packaged_part_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<packaged_part_terminal *>(s);
      }
   return NULL;
   }
// construction factory
packaged_part_terminal *packaged_part_terminal::Construct() {
   packaged_part_terminal *result = NULL;

   // create the packaged_part_terminal.
   result = new packaged_part_terminal();
   return result;
   }
bool packaged_part_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: packaged_part_terminal\r\n");

   // Check for the existence of all required attributes
   if (_terminal_of_package == NULL) {
      TRACE("ERROR: _terminal_of_package a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (part_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
