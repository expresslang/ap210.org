// Source for AP210 application object
//     thermal_isolation_requirement_assignment

// Precompiled include files
#include <StdAfx.h>

#include "thermal_isolation_requirement_assignment.h"

// Classes
#include <thermal_isolation_removal_structure.h>
#include <ee_requirement_occurrence.h>
#include <ee_requirement_occurrence.h>
#include <ee_requirement_occurrence.h>

thermal_isolation_requirement_assignment::thermal_isolation_requirement_assignment() {
   initialize();
   }
thermal_isolation_requirement_assignment::~thermal_isolation_requirement_assignment() {
   // Free string attributes
   }
// intialize data members
void thermal_isolation_requirement_assignment::initialize() {
   // Required attributes
   _resulting_structure = NULL;
   _thermal_isolation_spacing_requirement = NULL;
   _effective_current_capacity_requirement = NULL;
   _angular_orientation_requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int thermal_isolation_requirement_assignment::DynamicType(int ID) {
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
thermal_isolation_requirement_assignment *thermal_isolation_requirement_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<thermal_isolation_requirement_assignment *>(s);
      }
   return NULL;
   }
thermal_isolation_requirement_assignment *thermal_isolation_requirement_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<thermal_isolation_requirement_assignment *>(s);
      }
   return NULL;
   }
// construction factory
thermal_isolation_requirement_assignment *thermal_isolation_requirement_assignment::Construct() {
   thermal_isolation_requirement_assignment *result = NULL;

   // create the thermal_isolation_requirement_assignment.
   result = new thermal_isolation_requirement_assignment();
   return result;
   }
bool thermal_isolation_requirement_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: thermal_isolation_requirement_assignment\r\n");

   // Check for the existence of all required attributes
   if (_resulting_structure == NULL) {
      TRACE("ERROR: _resulting_structure a required attribute is NULL!\r\n");
      result = false;
      }
   if (_thermal_isolation_spacing_requirement == NULL) {
      TRACE("ERROR: _thermal_isolation_spacing_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_effective_current_capacity_requirement == NULL) {
      TRACE("ERROR: _effective_current_capacity_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_angular_orientation_requirement == NULL) {
      TRACE("ERROR: _angular_orientation_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
