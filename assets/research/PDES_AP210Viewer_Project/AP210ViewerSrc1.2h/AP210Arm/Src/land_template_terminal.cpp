// Source for AP210 application object
//     land_template_terminal

// Precompiled include files
#include <StdAfx.h>

#include "land_template_terminal.h"

// Classes
#include <land_physical_template.h>

land_template_terminal::land_template_terminal() {
   initialize();
   }
land_template_terminal::~land_template_terminal() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void land_template_terminal::initialize() {
   // Required attributes
   _associated_definition = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int land_template_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
land_template_terminal *land_template_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<land_template_terminal *>(s);
      }
   return NULL;
   }
land_template_terminal *land_template_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<land_template_terminal *>(s);
      }
   return NULL;
   }
// construction factory
land_template_terminal *land_template_terminal::Construct() {
   land_template_terminal *result = NULL;

   // create the land_template_terminal.
   result = new land_template_terminal();
   return result;
   }
bool land_template_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: land_template_terminal\r\n");

   // Check for the existence of all required attributes
   if (_associated_definition == NULL) {
      TRACE("ERROR: _associated_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_terminal_connection_zone == NULL) {
      TRACE("ERROR: _terminal_connection_zone a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_connection_zone_category == NULL) {
      TRACE("ERROR: _connection_zone_category a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
