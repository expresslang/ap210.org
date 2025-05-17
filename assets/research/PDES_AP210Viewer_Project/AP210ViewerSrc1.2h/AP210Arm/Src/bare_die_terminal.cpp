// Source for AP210 application object
//     bare_die_terminal

// Precompiled include files
#include <StdAfx.h>

#include "bare_die_terminal.h"

// Classes
#include <ee_material.h>
#include <connection_zone.h>

bare_die_terminal::bare_die_terminal() {
   initialize();
   }
bare_die_terminal::~bare_die_terminal() {
   // Free string attributes
   }
// intialize data members
void bare_die_terminal::initialize() {
   // Required attributes
   _material = NULL;
   _external_connection_area = NULL;

   // Optional attributes
   }
// Runtime type identification
int bare_die_terminal::DynamicType(int ID) {
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
bare_die_terminal *bare_die_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bare_die_terminal *>(s);
      }
   return NULL;
   }
bare_die_terminal *bare_die_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bare_die_terminal *>(s);
      }
   return NULL;
   }
// construction factory
bare_die_terminal *bare_die_terminal::Construct() {
   bare_die_terminal *result = NULL;

   // create the bare_die_terminal.
   result = new bare_die_terminal();
   return result;
   }
bool bare_die_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bare_die_terminal\r\n");

   // Check for the existence of all required attributes
   if (_material == NULL) {
      TRACE("ERROR: _material a required attribute is NULL!\r\n");
      result = false;
      }
   if (_external_connection_area == NULL) {
      TRACE("ERROR: _external_connection_area a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (minimally_defined_bare_die_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
