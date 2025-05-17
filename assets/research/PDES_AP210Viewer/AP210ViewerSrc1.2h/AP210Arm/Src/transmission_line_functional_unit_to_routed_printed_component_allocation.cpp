// Source for AP210 application object
//     transmission_line_functional_unit_to_routed_printed_component_allocation

// Precompiled include files
#include <StdAfx.h>

#include "transmission_line_functional_unit_to_routed_printed_component_allocation.h"

// Classes

transmission_line_functional_unit_to_routed_printed_component_allocation::transmission_line_functional_unit_to_routed_printed_component_allocation() {
   initialize();
   }
transmission_line_functional_unit_to_routed_printed_component_allocation::~transmission_line_functional_unit_to_routed_printed_component_allocation() {
   // Free string attributes
   }
// intialize data members
void transmission_line_functional_unit_to_routed_printed_component_allocation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int transmission_line_functional_unit_to_routed_printed_component_allocation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = design_functional_unit_allocation_to_assembly_component::DynamicType(ID);
      }
   return result;
   }
transmission_line_functional_unit_to_routed_printed_component_allocation *transmission_line_functional_unit_to_routed_printed_component_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<transmission_line_functional_unit_to_routed_printed_component_allocation *>(s);
      }
   return NULL;
   }
transmission_line_functional_unit_to_routed_printed_component_allocation *transmission_line_functional_unit_to_routed_printed_component_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<transmission_line_functional_unit_to_routed_printed_component_allocation *>(s);
      }
   return NULL;
   }
// construction factory
transmission_line_functional_unit_to_routed_printed_component_allocation *transmission_line_functional_unit_to_routed_printed_component_allocation::Construct() {
   transmission_line_functional_unit_to_routed_printed_component_allocation *result = NULL;

   // create the transmission_line_functional_unit_to_routed_printed_component_allocation.
   result = new transmission_line_functional_unit_to_routed_printed_component_allocation();
   return result;
   }
bool transmission_line_functional_unit_to_routed_printed_component_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: transmission_line_functional_unit_to_routed_printed_component_allocation\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (design_functional_unit_allocation_to_assembly_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
