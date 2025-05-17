// Source for AP210 application object
//     reference_functional_unit_assignment_to_part

// Precompiled include files
#include <StdAfx.h>

#include "reference_functional_unit_assignment_to_part.h"

// Classes
#include <reference_composition_path.h>

reference_functional_unit_assignment_to_part::reference_functional_unit_assignment_to_part() {
   initialize();
   }
reference_functional_unit_assignment_to_part::~reference_functional_unit_assignment_to_part() {
   // Free string attributes
   if (_path_alias != NULL) {
      free(_path_alias);
     }
   if (_swap_code != NULL) {
      free(_swap_code);
     }
   }
// intialize data members
void reference_functional_unit_assignment_to_part::initialize() {
   // Required attributes
   _functional_design_definition_path = NULL;
   _path_alias = NULL;

   // Optional attributes
   _swap_code = NULL;
   }
// Runtime type identification
int reference_functional_unit_assignment_to_part::DynamicType(int ID) {
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
reference_functional_unit_assignment_to_part *reference_functional_unit_assignment_to_part::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<reference_functional_unit_assignment_to_part *>(s);
      }
   return NULL;
   }
reference_functional_unit_assignment_to_part *reference_functional_unit_assignment_to_part::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<reference_functional_unit_assignment_to_part *>(s);
      }
   return NULL;
   }
// construction factory
reference_functional_unit_assignment_to_part *reference_functional_unit_assignment_to_part::Construct() {
   reference_functional_unit_assignment_to_part *result = NULL;

   // create the reference_functional_unit_assignment_to_part.
   result = new reference_functional_unit_assignment_to_part();
   return result;
   }
bool reference_functional_unit_assignment_to_part::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: reference_functional_unit_assignment_to_part\r\n");

   // Check for the existence of all required attributes
   if (_functional_design_definition_path == NULL) {
      TRACE("ERROR: _functional_design_definition_path a required attribute is NULL!\r\n");
      result = false;
      }
   if (_implementation == NULL) {
      TRACE("ERROR: _implementation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_path_alias == NULL) {
      TRACE("ERROR: _path_alias a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
