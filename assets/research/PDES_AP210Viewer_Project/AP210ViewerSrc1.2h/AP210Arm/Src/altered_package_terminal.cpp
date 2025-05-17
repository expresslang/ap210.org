// Source for AP210 application object
//     altered_package_terminal

// Precompiled include files
#include <StdAfx.h>

#include "altered_package_terminal.h"

// Classes
#include <package_terminal.h>

altered_package_terminal::altered_package_terminal() {
   initialize();
   }
altered_package_terminal::~altered_package_terminal() {
   // Free string attributes
   }
// intialize data members
void altered_package_terminal::initialize() {
   // Required attributes
   _terminal_to_be_altered = NULL;

   // Optional attributes
   }
// Runtime type identification
int altered_package_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = package_terminal::DynamicType(ID);
      }
   return result;
   }
altered_package_terminal *altered_package_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<altered_package_terminal *>(s);
      }
   return NULL;
   }
altered_package_terminal *altered_package_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<altered_package_terminal *>(s);
      }
   return NULL;
   }
// construction factory
altered_package_terminal *altered_package_terminal::Construct() {
   altered_package_terminal *result = NULL;

   // create the altered_package_terminal.
   result = new altered_package_terminal();
   return result;
   }
bool altered_package_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: altered_package_terminal\r\n");

   // Check for the existence of all required attributes
   if (_terminal_to_be_altered == NULL) {
      TRACE("ERROR: _terminal_to_be_altered a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (package_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
