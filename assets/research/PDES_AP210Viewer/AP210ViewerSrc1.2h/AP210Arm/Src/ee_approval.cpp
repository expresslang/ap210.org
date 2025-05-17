// Source for AP210 application object
//     ee_approval

// Precompiled include files
#include <StdAfx.h>

#include "ee_approval.h"

// Classes
#include <ee_text.h>

ee_approval::ee_approval() {
   initialize();
   }
ee_approval::~ee_approval() {
   // Free string attributes
   }
// intialize data members
void ee_approval::initialize() {
   // Required attributes
   _purpose = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_approval::DynamicType(int ID) {
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
ee_approval *ee_approval::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_approval *>(s);
      }
   return NULL;
   }
ee_approval *ee_approval::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_approval *>(s);
      }
   return NULL;
   }
// construction factory
ee_approval *ee_approval::Construct() {
   ee_approval *result = NULL;

   // create the ee_approval.
   result = new ee_approval();
   return result;
   }
bool ee_approval::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_approval\r\n");

   // Check for the existence of all required attributes
   if (_purpose == NULL) {
      TRACE("ERROR: _purpose a required attribute is NULL!\r\n");
      result = false;
      }
   if (_authorizer == NULL) {
      TRACE("ERROR: _authorizer a required attribute is NULL!\r\n");
      result = false;
      }
   if (_approval_status == NULL) {
      TRACE("ERROR: _approval_status a required attribute is NULL!\r\n");
      result = false;
      }
   if (_signoff_date == NULL) {
      TRACE("ERROR: _signoff_date a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
