// Source for AP210 application object
//     interconnect_module_terminal

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_terminal.h"

// Classes

interconnect_module_terminal::interconnect_module_terminal() {
   initialize();
   }
interconnect_module_terminal::~interconnect_module_terminal() {
   // Free string attributes
   }
// intialize data members
void interconnect_module_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interconnect_module_terminal::DynamicType(int ID) {
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
interconnect_module_terminal *interconnect_module_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_terminal *>(s);
      }
   return NULL;
   }
interconnect_module_terminal *interconnect_module_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_terminal *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_terminal *interconnect_module_terminal::Construct() {
   interconnect_module_terminal *result = NULL;

   // create the interconnect_module_terminal.
   result = new interconnect_module_terminal();
   return result;
   }
bool interconnect_module_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_terminal\r\n");

   // Check for the existence of all required attributes
   if (_terminal_connection_zone == NULL) {
      TRACE("ERROR: _terminal_connection_zone a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (part_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
