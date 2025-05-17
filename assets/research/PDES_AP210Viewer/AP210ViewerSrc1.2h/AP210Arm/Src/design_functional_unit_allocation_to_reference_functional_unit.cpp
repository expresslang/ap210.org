// Source for AP210 application object
//     design_functional_unit_allocation_to_reference_functional_unit

// Precompiled include files
#include <StdAfx.h>

#include "design_functional_unit_allocation_to_reference_functional_unit.h"

// Classes
#include <reference_composition_path.h>
#include <design_composition_path.h>

design_functional_unit_allocation_to_reference_functional_unit::design_functional_unit_allocation_to_reference_functional_unit() {
   initialize();
   }
design_functional_unit_allocation_to_reference_functional_unit::~design_functional_unit_allocation_to_reference_functional_unit() {
   // Free string attributes
   }
// intialize data members
void design_functional_unit_allocation_to_reference_functional_unit::initialize() {
   // Required attributes
   _reference_definition_path = NULL;
   _design_definition_path = NULL;

   // Optional attributes
   }
// Runtime type identification
int design_functional_unit_allocation_to_reference_functional_unit::DynamicType(int ID) {
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
design_functional_unit_allocation_to_reference_functional_unit *design_functional_unit_allocation_to_reference_functional_unit::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_functional_unit_allocation_to_reference_functional_unit *>(s);
      }
   return NULL;
   }
design_functional_unit_allocation_to_reference_functional_unit *design_functional_unit_allocation_to_reference_functional_unit::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_functional_unit_allocation_to_reference_functional_unit *>(s);
      }
   return NULL;
   }
// construction factory
design_functional_unit_allocation_to_reference_functional_unit *design_functional_unit_allocation_to_reference_functional_unit::Construct() {
   design_functional_unit_allocation_to_reference_functional_unit *result = NULL;

   // create the design_functional_unit_allocation_to_reference_functional_unit.
   result = new design_functional_unit_allocation_to_reference_functional_unit();
   return result;
   }
bool design_functional_unit_allocation_to_reference_functional_unit::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_functional_unit_allocation_to_reference_functional_unit\r\n");

   // Check for the existence of all required attributes
   if (_reference_definition_path == NULL) {
      TRACE("ERROR: _reference_definition_path a required attribute is NULL!\r\n");
      result = false;
      }
   if (_design_definition_path == NULL) {
      TRACE("ERROR: _design_definition_path a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
