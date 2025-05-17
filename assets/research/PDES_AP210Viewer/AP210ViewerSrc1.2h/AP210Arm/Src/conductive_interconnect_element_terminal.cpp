// Source for AP210 application object
//     conductive_interconnect_element_terminal

// Precompiled include files
#include <StdAfx.h>

#include "conductive_interconnect_element_terminal.h"

// Classes
#include <connection_zone.h>

conductive_interconnect_element_terminal::conductive_interconnect_element_terminal() {
   initialize();
   }
conductive_interconnect_element_terminal::~conductive_interconnect_element_terminal() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void conductive_interconnect_element_terminal::initialize() {
   // Required attributes
   _connection = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int conductive_interconnect_element_terminal::DynamicType(int ID) {
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
conductive_interconnect_element_terminal *conductive_interconnect_element_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conductive_interconnect_element_terminal *>(s);
      }
   return NULL;
   }
conductive_interconnect_element_terminal *conductive_interconnect_element_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conductive_interconnect_element_terminal *>(s);
      }
   return NULL;
   }
// construction factory
conductive_interconnect_element_terminal *conductive_interconnect_element_terminal::Construct() {
   conductive_interconnect_element_terminal *result = NULL;

   // create the conductive_interconnect_element_terminal.
   result = new conductive_interconnect_element_terminal();
   return result;
   }
bool conductive_interconnect_element_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conductive_interconnect_element_terminal\r\n");

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
