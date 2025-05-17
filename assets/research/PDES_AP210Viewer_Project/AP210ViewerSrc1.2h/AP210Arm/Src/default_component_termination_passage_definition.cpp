// Source for AP210 application object
//     default_component_termination_passage_definition

// Precompiled include files
#include <StdAfx.h>

#include "default_component_termination_passage_definition.h"

// Classes
#include <length_data_element.h>
#include <length_data_element.h>

default_component_termination_passage_definition::default_component_termination_passage_definition() {
   initialize();
   }
default_component_termination_passage_definition::~default_component_termination_passage_definition() {
   // Free string attributes
   }
// intialize data members
void default_component_termination_passage_definition::initialize() {
   // Required attributes
   _minimum_allowed_component_terminal_extent = NULL;
   _maximum_allowed_component_terminal_extent = NULL;

   // Optional attributes
   }
// Runtime type identification
int default_component_termination_passage_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = passage_technology::DynamicType(ID);
      }
   return result;
   }
default_component_termination_passage_definition *default_component_termination_passage_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<default_component_termination_passage_definition *>(s);
      }
   return NULL;
   }
default_component_termination_passage_definition *default_component_termination_passage_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<default_component_termination_passage_definition *>(s);
      }
   return NULL;
   }
// construction factory
default_component_termination_passage_definition *default_component_termination_passage_definition::Construct() {
   default_component_termination_passage_definition *result = NULL;

   // create the default_component_termination_passage_definition.
   result = new default_component_termination_passage_definition();
   return result;
   }
bool default_component_termination_passage_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: default_component_termination_passage_definition\r\n");

   // Check for the existence of all required attributes
   if (_minimum_allowed_component_terminal_extent == NULL) {
      TRACE("ERROR: _minimum_allowed_component_terminal_extent a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_allowed_component_terminal_extent == NULL) {
      TRACE("ERROR: _maximum_allowed_component_terminal_extent a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (passage_technology::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
