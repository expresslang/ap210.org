// Source for AP210 application object
//     functional_unit_requirement_allocation

// Precompiled include files
#include <StdAfx.h>

#include "functional_unit_requirement_allocation.h"

// Classes
#include <ee_requirement_occurrence.h>
#include <functional_unit.h>

functional_unit_requirement_allocation::functional_unit_requirement_allocation() {
   initialize();
   }
functional_unit_requirement_allocation::~functional_unit_requirement_allocation() {
   // Free string attributes
   }
// intialize data members
void functional_unit_requirement_allocation::initialize() {
   // Required attributes
   _functional_requirement = NULL;
   _functional_unit_assignment = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_unit_requirement_allocation::DynamicType(int ID) {
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
functional_unit_requirement_allocation *functional_unit_requirement_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_unit_requirement_allocation *>(s);
      }
   return NULL;
   }
functional_unit_requirement_allocation *functional_unit_requirement_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_unit_requirement_allocation *>(s);
      }
   return NULL;
   }
// construction factory
functional_unit_requirement_allocation *functional_unit_requirement_allocation::Construct() {
   functional_unit_requirement_allocation *result = NULL;

   // create the functional_unit_requirement_allocation.
   result = new functional_unit_requirement_allocation();
   return result;
   }
bool functional_unit_requirement_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_unit_requirement_allocation\r\n");

   // Check for the existence of all required attributes
   if (_functional_requirement == NULL) {
      TRACE("ERROR: _functional_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_functional_unit_assignment == NULL) {
      TRACE("ERROR: _functional_unit_assignment a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
