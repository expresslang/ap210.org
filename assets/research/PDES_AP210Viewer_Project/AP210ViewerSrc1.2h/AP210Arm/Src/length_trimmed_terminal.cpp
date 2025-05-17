// Source for AP210 application object
//     length_trimmed_terminal

// Precompiled include files
#include <StdAfx.h>

#include "length_trimmed_terminal.h"

// Classes
#include <length_data_element.h>
#include <length_data_element.h>

length_trimmed_terminal::length_trimmed_terminal() {
   initialize();
   }
length_trimmed_terminal::~length_trimmed_terminal() {
   // Free string attributes
   }
// intialize data members
void length_trimmed_terminal::initialize() {
   // Required attributes
   _maximum_trimmed_length = NULL;
   _minimum_trimmed_length = NULL;

   // Optional attributes
   }
// Runtime type identification
int length_trimmed_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = altered_package_terminal::DynamicType(ID);
      }
   return result;
   }
length_trimmed_terminal *length_trimmed_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<length_trimmed_terminal *>(s);
      }
   return NULL;
   }
length_trimmed_terminal *length_trimmed_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<length_trimmed_terminal *>(s);
      }
   return NULL;
   }
// construction factory
length_trimmed_terminal *length_trimmed_terminal::Construct() {
   length_trimmed_terminal *result = NULL;

   // create the length_trimmed_terminal.
   result = new length_trimmed_terminal();
   return result;
   }
bool length_trimmed_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: length_trimmed_terminal\r\n");

   // Check for the existence of all required attributes
   if (_maximum_trimmed_length == NULL) {
      TRACE("ERROR: _maximum_trimmed_length a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_trimmed_length == NULL) {
      TRACE("ERROR: _minimum_trimmed_length a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (altered_package_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
