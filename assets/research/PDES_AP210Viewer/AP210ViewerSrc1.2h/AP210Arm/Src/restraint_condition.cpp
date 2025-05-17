// Source for AP210 application object
//     restraint_condition

// Precompiled include files
#include <StdAfx.h>

#include "restraint_condition.h"

// Classes
#include <ee_requirement_occurrence.h>

restraint_condition::restraint_condition() {
   initialize();
   }
restraint_condition::~restraint_condition() {
   // Free string attributes
   }
// intialize data members
void restraint_condition::initialize() {
   // Required attributes
   _restraint_description = NULL;

   // Optional attributes
   }
// Runtime type identification
int restraint_condition::DynamicType(int ID) {
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
restraint_condition *restraint_condition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<restraint_condition *>(s);
      }
   return NULL;
   }
restraint_condition *restraint_condition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<restraint_condition *>(s);
      }
   return NULL;
   }
// construction factory
restraint_condition *restraint_condition::Construct() {
   restraint_condition *result = NULL;

   // create the restraint_condition.
   result = new restraint_condition();
   return result;
   }
bool restraint_condition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: restraint_condition\r\n");

   // Check for the existence of all required attributes
   if (_restraint_description == NULL) {
      TRACE("ERROR: _restraint_description a required attribute is NULL!\r\n");
      result = false;
      }
   if (_applied_to == NULL) {
      TRACE("ERROR: _applied_to a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
