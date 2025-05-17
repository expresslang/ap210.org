// Source for AP210 application object
//     component_termination_passage

// Precompiled include files
#include <StdAfx.h>

#include "component_termination_passage.h"

// Classes

component_termination_passage::component_termination_passage() {
   initialize();
   }
component_termination_passage::~component_termination_passage() {
   // Free string attributes
   }
// intialize data members
void component_termination_passage::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int component_termination_passage::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = plated_passage::DynamicType(ID);
      }
   return result;
   }
component_termination_passage *component_termination_passage::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_termination_passage *>(s);
      }
   return NULL;
   }
component_termination_passage *component_termination_passage::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_termination_passage *>(s);
      }
   return NULL;
   }
// construction factory
component_termination_passage *component_termination_passage::Construct() {
   component_termination_passage *result = NULL;

   // create the component_termination_passage.
   result = new component_termination_passage();
   return result;
   }
bool component_termination_passage::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_termination_passage\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (plated_passage::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
