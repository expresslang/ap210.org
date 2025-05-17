// Source for AP210 application object
//     security_classification

// Precompiled include files
#include <StdAfx.h>

#include "security_classification.h"

// Classes
#include <person.h>
#include <ee_approval.h>

security_classification::security_classification() {
   initialize();
   }
security_classification::~security_classification() {
   // Free string attributes
   }
// intialize data members
void security_classification::initialize() {
   // Required attributes
   _classification_officer = NULL;
   _security_classification_approval = NULL;

   // Optional attributes
   }
// Runtime type identification
int security_classification::DynamicType(int ID) {
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
security_classification *security_classification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<security_classification *>(s);
      }
   return NULL;
   }
security_classification *security_classification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<security_classification *>(s);
      }
   return NULL;
   }
// construction factory
security_classification *security_classification::Construct() {
   security_classification *result = NULL;

   // create the security_classification.
   result = new security_classification();
   return result;
   }
bool security_classification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: security_classification\r\n");

   // Check for the existence of all required attributes
   if (_classification_officer == NULL) {
      TRACE("ERROR: _classification_officer a required attribute is NULL!\r\n");
      result = false;
      }
   if (_security_classification_approval == NULL) {
      TRACE("ERROR: _security_classification_approval a required attribute is NULL!\r\n");
      result = false;
      }
   if (_classification_date == NULL) {
      TRACE("ERROR: _classification_date a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
