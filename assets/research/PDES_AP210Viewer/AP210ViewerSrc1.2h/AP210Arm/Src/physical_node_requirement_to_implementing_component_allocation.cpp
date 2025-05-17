// Source for AP210 application object
//     physical_node_requirement_to_implementing_component_allocation

// Precompiled include files
#include <StdAfx.h>

#include "physical_node_requirement_to_implementing_component_allocation.h"

// Classes
#include <physical_connectivity_definition.h>
#include <assembly_component.h>

physical_node_requirement_to_implementing_component_allocation::physical_node_requirement_to_implementing_component_allocation() {
   initialize();
   }
physical_node_requirement_to_implementing_component_allocation::~physical_node_requirement_to_implementing_component_allocation() {
   // Free string attributes
   }
// intialize data members
void physical_node_requirement_to_implementing_component_allocation::initialize() {
   // Required attributes
   _physical_node_requirement = NULL;
   _implementation_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int physical_node_requirement_to_implementing_component_allocation::DynamicType(int ID) {
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
physical_node_requirement_to_implementing_component_allocation *physical_node_requirement_to_implementing_component_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_node_requirement_to_implementing_component_allocation *>(s);
      }
   return NULL;
   }
physical_node_requirement_to_implementing_component_allocation *physical_node_requirement_to_implementing_component_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_node_requirement_to_implementing_component_allocation *>(s);
      }
   return NULL;
   }
// construction factory
physical_node_requirement_to_implementing_component_allocation *physical_node_requirement_to_implementing_component_allocation::Construct() {
   physical_node_requirement_to_implementing_component_allocation *result = NULL;

   // create the physical_node_requirement_to_implementing_component_allocation.
   result = new physical_node_requirement_to_implementing_component_allocation();
   return result;
   }
bool physical_node_requirement_to_implementing_component_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_node_requirement_to_implementing_component_allocation\r\n");

   // Check for the existence of all required attributes
   if (_physical_node_requirement == NULL) {
      TRACE("ERROR: _physical_node_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_implementation_component == NULL) {
      TRACE("ERROR: _implementation_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
