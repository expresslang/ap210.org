// Source for AP210 application object
//     design_functional_unit_allocation_to_fabrication_joint

// Precompiled include files
#include <StdAfx.h>

#include "design_functional_unit_allocation_to_fabrication_joint.h"

// Classes
#include <design_composition_path.h>
#include <fabrication_joint.h>

design_functional_unit_allocation_to_fabrication_joint::design_functional_unit_allocation_to_fabrication_joint() {
   initialize();
   }
design_functional_unit_allocation_to_fabrication_joint::~design_functional_unit_allocation_to_fabrication_joint() {
   // Free string attributes
   }
// intialize data members
void design_functional_unit_allocation_to_fabrication_joint::initialize() {
   // Required attributes
   _functional_design_definition_path = NULL;
   _implementation = NULL;

   // Optional attributes
   }
// Runtime type identification
int design_functional_unit_allocation_to_fabrication_joint::DynamicType(int ID) {
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
design_functional_unit_allocation_to_fabrication_joint *design_functional_unit_allocation_to_fabrication_joint::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_functional_unit_allocation_to_fabrication_joint *>(s);
      }
   return NULL;
   }
design_functional_unit_allocation_to_fabrication_joint *design_functional_unit_allocation_to_fabrication_joint::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_functional_unit_allocation_to_fabrication_joint *>(s);
      }
   return NULL;
   }
// construction factory
design_functional_unit_allocation_to_fabrication_joint *design_functional_unit_allocation_to_fabrication_joint::Construct() {
   design_functional_unit_allocation_to_fabrication_joint *result = NULL;

   // create the design_functional_unit_allocation_to_fabrication_joint.
   result = new design_functional_unit_allocation_to_fabrication_joint();
   return result;
   }
bool design_functional_unit_allocation_to_fabrication_joint::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_functional_unit_allocation_to_fabrication_joint\r\n");

   // Check for the existence of all required attributes
   if (_functional_design_definition_path == NULL) {
      TRACE("ERROR: _functional_design_definition_path a required attribute is NULL!\r\n");
      result = false;
      }
   if (_implementation == NULL) {
      TRACE("ERROR: _implementation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
