// Source for AP210 application object
//     equivalent_functional_unit_definition_assignment

// Precompiled include files
#include <StdAfx.h>

#include "equivalent_functional_unit_definition_assignment.h"

// Classes

equivalent_functional_unit_definition_assignment::equivalent_functional_unit_definition_assignment() {
   initialize();
   }
equivalent_functional_unit_definition_assignment::~equivalent_functional_unit_definition_assignment() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void equivalent_functional_unit_definition_assignment::initialize() {
   // Required attributes
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int equivalent_functional_unit_definition_assignment::DynamicType(int ID) {
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
equivalent_functional_unit_definition_assignment *equivalent_functional_unit_definition_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<equivalent_functional_unit_definition_assignment *>(s);
      }
   return NULL;
   }
equivalent_functional_unit_definition_assignment *equivalent_functional_unit_definition_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<equivalent_functional_unit_definition_assignment *>(s);
      }
   return NULL;
   }
// construction factory
equivalent_functional_unit_definition_assignment *equivalent_functional_unit_definition_assignment::Construct() {
   equivalent_functional_unit_definition_assignment *result = NULL;

   // create the equivalent_functional_unit_definition_assignment.
   result = new equivalent_functional_unit_definition_assignment();
   return result;
   }
bool equivalent_functional_unit_definition_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: equivalent_functional_unit_definition_assignment\r\n");

   // Check for the existence of all required attributes
   if (_equivalent_functional_unit_definitions == NULL) {
      TRACE("ERROR: _equivalent_functional_unit_definitions a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
