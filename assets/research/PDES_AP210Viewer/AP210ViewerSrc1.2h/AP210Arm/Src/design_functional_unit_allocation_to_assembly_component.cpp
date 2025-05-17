// Source for AP210 application object
//     design_functional_unit_allocation_to_assembly_component

// Precompiled include files
#include <StdAfx.h>

#include "design_functional_unit_allocation_to_assembly_component.h"

// Classes
#include <design_composition_path.h>
#include <assembly_component.h>

design_functional_unit_allocation_to_assembly_component::design_functional_unit_allocation_to_assembly_component() {
   initialize();
   }
design_functional_unit_allocation_to_assembly_component::~design_functional_unit_allocation_to_assembly_component() {
   // Free string attributes
   if (_path_alias != NULL) {
      free(_path_alias);
     }
   if (_swap_code != NULL) {
      free(_swap_code);
     }
   }
// intialize data members
void design_functional_unit_allocation_to_assembly_component::initialize() {
   // Required attributes
   _functional_design_definition_path = NULL;
   _implementation = NULL;
   _path_alias = NULL;
   _swap_code = NULL;

   // Optional attributes
   }
// Runtime type identification
int design_functional_unit_allocation_to_assembly_component::DynamicType(int ID) {
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
design_functional_unit_allocation_to_assembly_component *design_functional_unit_allocation_to_assembly_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_functional_unit_allocation_to_assembly_component *>(s);
      }
   return NULL;
   }
design_functional_unit_allocation_to_assembly_component *design_functional_unit_allocation_to_assembly_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_functional_unit_allocation_to_assembly_component *>(s);
      }
   return NULL;
   }
// construction factory
design_functional_unit_allocation_to_assembly_component *design_functional_unit_allocation_to_assembly_component::Construct() {
   design_functional_unit_allocation_to_assembly_component *result = NULL;

   // create the design_functional_unit_allocation_to_assembly_component.
   result = new design_functional_unit_allocation_to_assembly_component();
   return result;
   }
bool design_functional_unit_allocation_to_assembly_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_functional_unit_allocation_to_assembly_component\r\n");

   // Check for the existence of all required attributes
   if (_functional_design_definition_path == NULL) {
      TRACE("ERROR: _functional_design_definition_path a required attribute is NULL!\r\n");
      result = false;
      }
   if (_implementation == NULL) {
      TRACE("ERROR: _implementation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_global_swappable == NULL) {
      TRACE("ERROR: _global_swappable a required attribute is NULL!\r\n");
      result = false;
      }
   if (_local_swappable == NULL) {
      TRACE("ERROR: _local_swappable a required attribute is NULL!\r\n");
      result = false;
      }
   if (_path_alias == NULL) {
      TRACE("ERROR: _path_alias a required attribute is NULL!\r\n");
      result = false;
      }
   if (_swap_code == NULL) {
      TRACE("ERROR: _swap_code a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
