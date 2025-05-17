// Source for AP210 application object
//     gate_path_swap_specification

// Precompiled include files
#include <StdAfx.h>

#include "gate_path_swap_specification.h"

// Classes

gate_path_swap_specification::gate_path_swap_specification() {
   initialize();
   }
gate_path_swap_specification::~gate_path_swap_specification() {
   // Free string attributes
   }
// intialize data members
void gate_path_swap_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int gate_path_swap_specification::DynamicType(int ID) {
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
gate_path_swap_specification *gate_path_swap_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<gate_path_swap_specification *>(s);
      }
   return NULL;
   }
gate_path_swap_specification *gate_path_swap_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<gate_path_swap_specification *>(s);
      }
   return NULL;
   }
// construction factory
gate_path_swap_specification *gate_path_swap_specification::Construct() {
   gate_path_swap_specification *result = NULL;

   // create the gate_path_swap_specification.
   result = new gate_path_swap_specification();
   return result;
   }
bool gate_path_swap_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: gate_path_swap_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (change_design_object_management_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
