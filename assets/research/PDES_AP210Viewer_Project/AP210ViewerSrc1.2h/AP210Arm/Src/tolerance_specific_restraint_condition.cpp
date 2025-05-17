// Source for AP210 application object
//     tolerance_specific_restraint_condition

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_specific_restraint_condition.h"

// Classes

tolerance_specific_restraint_condition::tolerance_specific_restraint_condition() {
   initialize();
   }
tolerance_specific_restraint_condition::~tolerance_specific_restraint_condition() {
   // Free string attributes
   }
// intialize data members
void tolerance_specific_restraint_condition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int tolerance_specific_restraint_condition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = restraint_condition::DynamicType(ID);
      }
   return result;
   }
tolerance_specific_restraint_condition *tolerance_specific_restraint_condition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_specific_restraint_condition *>(s);
      }
   return NULL;
   }
tolerance_specific_restraint_condition *tolerance_specific_restraint_condition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_specific_restraint_condition *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_specific_restraint_condition *tolerance_specific_restraint_condition::Construct() {
   tolerance_specific_restraint_condition *result = NULL;

   // create the tolerance_specific_restraint_condition.
   result = new tolerance_specific_restraint_condition();
   return result;
   }
bool tolerance_specific_restraint_condition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_specific_restraint_condition\r\n");

   // Check for the existence of all required attributes
   if (_affected_tolerances == NULL) {
      TRACE("ERROR: _affected_tolerances a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (restraint_condition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
