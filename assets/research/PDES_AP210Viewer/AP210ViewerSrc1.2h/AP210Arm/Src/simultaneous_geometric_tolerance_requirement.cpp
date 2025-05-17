// Source for AP210 application object
//     simultaneous_geometric_tolerance_requirement

// Precompiled include files
#include <StdAfx.h>

#include "simultaneous_geometric_tolerance_requirement.h"

// Classes

simultaneous_geometric_tolerance_requirement::simultaneous_geometric_tolerance_requirement() {
   initialize();
   }
simultaneous_geometric_tolerance_requirement::~simultaneous_geometric_tolerance_requirement() {
   // Free string attributes
   }
// intialize data members
void simultaneous_geometric_tolerance_requirement::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int simultaneous_geometric_tolerance_requirement::DynamicType(int ID) {
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
simultaneous_geometric_tolerance_requirement *simultaneous_geometric_tolerance_requirement::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<simultaneous_geometric_tolerance_requirement *>(s);
      }
   return NULL;
   }
simultaneous_geometric_tolerance_requirement *simultaneous_geometric_tolerance_requirement::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<simultaneous_geometric_tolerance_requirement *>(s);
      }
   return NULL;
   }
// construction factory
simultaneous_geometric_tolerance_requirement *simultaneous_geometric_tolerance_requirement::Construct() {
   simultaneous_geometric_tolerance_requirement *result = NULL;

   // create the simultaneous_geometric_tolerance_requirement.
   result = new simultaneous_geometric_tolerance_requirement();
   return result;
   }
bool simultaneous_geometric_tolerance_requirement::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: simultaneous_geometric_tolerance_requirement\r\n");

   // Check for the existence of all required attributes
   if (_grouped_geometric_tolerances == NULL) {
      TRACE("ERROR: _grouped_geometric_tolerances a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
