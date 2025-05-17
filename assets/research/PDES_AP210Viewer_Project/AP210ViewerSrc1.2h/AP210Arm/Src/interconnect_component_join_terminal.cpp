// Source for AP210 application object
//     interconnect_component_join_terminal

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_component_join_terminal.h"

// Classes
#include <connection_zone.h>

interconnect_component_join_terminal::interconnect_component_join_terminal() {
   initialize();
   }
interconnect_component_join_terminal::~interconnect_component_join_terminal() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void interconnect_component_join_terminal::initialize() {
   // Required attributes
   _connection = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int interconnect_component_join_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = component_terminal::DynamicType(ID);
      }
   return result;
   }
interconnect_component_join_terminal *interconnect_component_join_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_component_join_terminal *>(s);
      }
   return NULL;
   }
interconnect_component_join_terminal *interconnect_component_join_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_component_join_terminal *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_component_join_terminal *interconnect_component_join_terminal::Construct() {
   interconnect_component_join_terminal *result = NULL;

   // create the interconnect_component_join_terminal.
   result = new interconnect_component_join_terminal();
   return result;
   }
bool interconnect_component_join_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_component_join_terminal\r\n");

   // Check for the existence of all required attributes
   if (_connection == NULL) {
      TRACE("ERROR: _connection a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (component_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
