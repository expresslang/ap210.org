// Source for AP210 application object
//     termination_constraint

// Precompiled include files
#include <StdAfx.h>

#include "termination_constraint.h"

// Classes
#include <ee_requirement_occurrence.h>

termination_constraint::termination_constraint() {
   initialize();
   }
termination_constraint::~termination_constraint() {
   // Free string attributes
   }
// intialize data members
void termination_constraint::initialize() {
   // Required attributes
   _termination_usage_constraint = NULL;

   // Optional attributes
   }
// Runtime type identification
int termination_constraint::DynamicType(int ID) {
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
termination_constraint *termination_constraint::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<termination_constraint *>(s);
      }
   return NULL;
   }
termination_constraint *termination_constraint::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<termination_constraint *>(s);
      }
   return NULL;
   }
// construction factory
termination_constraint *termination_constraint::Construct() {
   termination_constraint *result = NULL;

   // create the termination_constraint.
   result = new termination_constraint();
   return result;
   }
bool termination_constraint::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: termination_constraint\r\n");

   // Check for the existence of all required attributes
   if (_constrained_termination == NULL) {
      TRACE("ERROR: _constrained_termination a required attribute is NULL!\r\n");
      result = false;
      }
   if (_termination_usage_constraint == NULL) {
      TRACE("ERROR: _termination_usage_constraint a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
