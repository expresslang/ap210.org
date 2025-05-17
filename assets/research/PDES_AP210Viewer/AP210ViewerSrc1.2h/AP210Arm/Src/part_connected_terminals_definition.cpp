// Source for AP210 application object
//     part_connected_terminals_definition

// Precompiled include files
#include <StdAfx.h>

#include "part_connected_terminals_definition.h"

// Classes

part_connected_terminals_definition::part_connected_terminals_definition() {
   initialize();
   }
part_connected_terminals_definition::~part_connected_terminals_definition() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void part_connected_terminals_definition::initialize() {
   // Required attributes
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int part_connected_terminals_definition::DynamicType(int ID) {
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
part_connected_terminals_definition *part_connected_terminals_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_connected_terminals_definition *>(s);
      }
   return NULL;
   }
part_connected_terminals_definition *part_connected_terminals_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_connected_terminals_definition *>(s);
      }
   return NULL;
   }
// construction factory
part_connected_terminals_definition *part_connected_terminals_definition::Construct() {
   part_connected_terminals_definition *result = NULL;

   // create the part_connected_terminals_definition.
   result = new part_connected_terminals_definition();
   return result;
   }
bool part_connected_terminals_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_connected_terminals_definition\r\n");

   // Check for the existence of all required attributes
   if (_connected_terminals == NULL) {
      TRACE("ERROR: _connected_terminals a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
