// Source for AP210 application object
//     functional_specification_to_requirement_occurrence_assignment

// Precompiled include files
#include <StdAfx.h>

#include "functional_specification_to_requirement_occurrence_assignment.h"

// Classes
#include <functional_specification.h>
#include <ee_requirement_occurrence.h>

functional_specification_to_requirement_occurrence_assignment::functional_specification_to_requirement_occurrence_assignment() {
   initialize();
   }
functional_specification_to_requirement_occurrence_assignment::~functional_specification_to_requirement_occurrence_assignment() {
   // Free string attributes
   }
// intialize data members
void functional_specification_to_requirement_occurrence_assignment::initialize() {
   // Required attributes
   _specification_data = NULL;
   _assigned_requirement_occurrence = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_specification_to_requirement_occurrence_assignment::DynamicType(int ID) {
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
functional_specification_to_requirement_occurrence_assignment *functional_specification_to_requirement_occurrence_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_specification_to_requirement_occurrence_assignment *>(s);
      }
   return NULL;
   }
functional_specification_to_requirement_occurrence_assignment *functional_specification_to_requirement_occurrence_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_specification_to_requirement_occurrence_assignment *>(s);
      }
   return NULL;
   }
// construction factory
functional_specification_to_requirement_occurrence_assignment *functional_specification_to_requirement_occurrence_assignment::Construct() {
   functional_specification_to_requirement_occurrence_assignment *result = NULL;

   // create the functional_specification_to_requirement_occurrence_assignment.
   result = new functional_specification_to_requirement_occurrence_assignment();
   return result;
   }
bool functional_specification_to_requirement_occurrence_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_specification_to_requirement_occurrence_assignment\r\n");

   // Check for the existence of all required attributes
   if (_specification_data == NULL) {
      TRACE("ERROR: _specification_data a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_requirement_occurrence == NULL) {
      TRACE("ERROR: _assigned_requirement_occurrence a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
