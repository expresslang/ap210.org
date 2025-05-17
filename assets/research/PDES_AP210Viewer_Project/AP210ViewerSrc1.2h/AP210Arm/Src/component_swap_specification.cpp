// Source for AP210 application object
//     component_swap_specification

// Precompiled include files
#include <StdAfx.h>

#include "component_swap_specification.h"

// Classes

component_swap_specification::component_swap_specification() {
   initialize();
   }
component_swap_specification::~component_swap_specification() {
   // Free string attributes
   }
// intialize data members
void component_swap_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int component_swap_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = change_design_object_management_relationship::DynamicType(ID);
      }
   return result;
   }
component_swap_specification *component_swap_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_swap_specification *>(s);
      }
   return NULL;
   }
component_swap_specification *component_swap_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_swap_specification *>(s);
      }
   return NULL;
   }
// construction factory
component_swap_specification *component_swap_specification::Construct() {
   component_swap_specification *result = NULL;

   // create the component_swap_specification.
   result = new component_swap_specification();
   return result;
   }
bool component_swap_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_swap_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (change_design_object_management_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
