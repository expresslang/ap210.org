// Source for AP210 application object
//     wire_terminal

// Precompiled include files
#include <StdAfx.h>

#include "wire_terminal.h"

// Classes
#include <length_data_element.h>
#include <length_data_element.h>

wire_terminal::wire_terminal() {
   initialize();
   }
wire_terminal::~wire_terminal() {
   // Free string attributes
   }
// intialize data members
void wire_terminal::initialize() {
   // Required attributes
   _maximum_wire_terminal_length = NULL;
   _minimum_wire_terminal_length = NULL;

   // Optional attributes
   }
// Runtime type identification
int wire_terminal::DynamicType(int ID) {
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
wire_terminal *wire_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<wire_terminal *>(s);
      }
   return NULL;
   }
wire_terminal *wire_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<wire_terminal *>(s);
      }
   return NULL;
   }
// construction factory
wire_terminal *wire_terminal::Construct() {
   wire_terminal *result = NULL;

   // create the wire_terminal.
   result = new wire_terminal();
   return result;
   }
bool wire_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: wire_terminal\r\n");

   // Check for the existence of all required attributes
   if (_maximum_wire_terminal_length == NULL) {
      TRACE("ERROR: _maximum_wire_terminal_length a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_wire_terminal_length == NULL) {
      TRACE("ERROR: _minimum_wire_terminal_length a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (package_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
