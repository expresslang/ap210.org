// Source for AP210 application object
//     component_termination_passage_join_terminal

// Precompiled include files
#include <StdAfx.h>

#include "component_termination_passage_join_terminal.h"

// Classes

component_termination_passage_join_terminal::component_termination_passage_join_terminal() {
   initialize();
   }
component_termination_passage_join_terminal::~component_termination_passage_join_terminal() {
   // Free string attributes
   }
// intialize data members
void component_termination_passage_join_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int component_termination_passage_join_terminal::DynamicType(int ID) {
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
component_termination_passage_join_terminal *component_termination_passage_join_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_termination_passage_join_terminal *>(s);
      }
   return NULL;
   }
component_termination_passage_join_terminal *component_termination_passage_join_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_termination_passage_join_terminal *>(s);
      }
   return NULL;
   }
// construction factory
component_termination_passage_join_terminal *component_termination_passage_join_terminal::Construct() {
   component_termination_passage_join_terminal *result = NULL;

   // create the component_termination_passage_join_terminal.
   result = new component_termination_passage_join_terminal();
   return result;
   }
bool component_termination_passage_join_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_termination_passage_join_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
