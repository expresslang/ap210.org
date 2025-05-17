// Source for AP210 application object
//     separate_geometric_tolerance_requirement

// Precompiled include files
#include <StdAfx.h>

#include "separate_geometric_tolerance_requirement.h"

// Classes

separate_geometric_tolerance_requirement::separate_geometric_tolerance_requirement() {
   initialize();
   }
separate_geometric_tolerance_requirement::~separate_geometric_tolerance_requirement() {
   // Free string attributes
   }
// intialize data members
void separate_geometric_tolerance_requirement::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int separate_geometric_tolerance_requirement::DynamicType(int ID) {
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
separate_geometric_tolerance_requirement *separate_geometric_tolerance_requirement::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<separate_geometric_tolerance_requirement *>(s);
      }
   return NULL;
   }
separate_geometric_tolerance_requirement *separate_geometric_tolerance_requirement::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<separate_geometric_tolerance_requirement *>(s);
      }
   return NULL;
   }
// construction factory
separate_geometric_tolerance_requirement *separate_geometric_tolerance_requirement::Construct() {
   separate_geometric_tolerance_requirement *result = NULL;

   // create the separate_geometric_tolerance_requirement.
   result = new separate_geometric_tolerance_requirement();
   return result;
   }
bool separate_geometric_tolerance_requirement::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: separate_geometric_tolerance_requirement\r\n");

   // Check for the existence of all required attributes
   if (_separated_geometric_tolerances == NULL) {
      TRACE("ERROR: _separated_geometric_tolerances a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
