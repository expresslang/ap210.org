// Source for AP210 application object
//     constraint_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "constraint_occurrence.h"

// Classes
#include <ee_rule_version.h>

constraint_occurrence::constraint_occurrence() {
   initialize();
   }
constraint_occurrence::~constraint_occurrence() {
   // Free string attributes
   }
// intialize data members
void constraint_occurrence::initialize() {
   // Required attributes
   _design_constraint = NULL;

   // Optional attributes
   }
// Runtime type identification
int constraint_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_requirement_occurrence::DynamicType(ID);
      }
   return result;
   }
constraint_occurrence *constraint_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<constraint_occurrence *>(s);
      }
   return NULL;
   }
constraint_occurrence *constraint_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<constraint_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
constraint_occurrence *constraint_occurrence::Construct() {
   constraint_occurrence *result = NULL;

   // create the constraint_occurrence.
   result = new constraint_occurrence();
   return result;
   }
bool constraint_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: constraint_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_design_constraint == NULL) {
      TRACE("ERROR: _design_constraint a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (ee_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
