// Source for AP210 application object
//     interface_component_allocation

// Precompiled include files
#include <StdAfx.h>

#include "interface_component_allocation.h"

// Classes
#include <interface_component.h>
#include <mating_connector_component.h>

interface_component_allocation::interface_component_allocation() {
   initialize();
   }
interface_component_allocation::~interface_component_allocation() {
   // Free string attributes
   }
// intialize data members
void interface_component_allocation::initialize() {
   // Required attributes
   _mating_solution = NULL;
   _mating_requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int interface_component_allocation::DynamicType(int ID) {
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
interface_component_allocation *interface_component_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interface_component_allocation *>(s);
      }
   return NULL;
   }
interface_component_allocation *interface_component_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interface_component_allocation *>(s);
      }
   return NULL;
   }
// construction factory
interface_component_allocation *interface_component_allocation::Construct() {
   interface_component_allocation *result = NULL;

   // create the interface_component_allocation.
   result = new interface_component_allocation();
   return result;
   }
bool interface_component_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interface_component_allocation\r\n");

   // Check for the existence of all required attributes
   if (_mating_solution == NULL) {
      TRACE("ERROR: _mating_solution a required attribute is NULL!\r\n");
      result = false;
      }
   if (_mating_requirement == NULL) {
      TRACE("ERROR: _mating_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
