// Source for AP210 application object
//     printed_component_join_terminal

// Precompiled include files
#include <StdAfx.h>

#include "printed_component_join_terminal.h"

// Classes
#include <connection_zone.h>

printed_component_join_terminal::printed_component_join_terminal() {
   initialize();
   }
printed_component_join_terminal::~printed_component_join_terminal() {
   // Free string attributes
   }
// intialize data members
void printed_component_join_terminal::initialize() {
   // Required attributes
   _connection = NULL;

   // Optional attributes
   }
// Runtime type identification
int printed_component_join_terminal::DynamicType(int ID) {
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
printed_component_join_terminal *printed_component_join_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<printed_component_join_terminal *>(s);
      }
   return NULL;
   }
printed_component_join_terminal *printed_component_join_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<printed_component_join_terminal *>(s);
      }
   return NULL;
   }
// construction factory
printed_component_join_terminal *printed_component_join_terminal::Construct() {
   printed_component_join_terminal *result = NULL;

   // create the printed_component_join_terminal.
   result = new printed_component_join_terminal();
   return result;
   }
bool printed_component_join_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: printed_component_join_terminal\r\n");

   // Check for the existence of all required attributes
   if (_connection == NULL) {
      TRACE("ERROR: _connection a required attribute is NULL!\r\n");
      result = false;
      }
   if (_stratum_concept_implementation_component == NULL) {
      TRACE("ERROR: _stratum_concept_implementation_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (component_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
