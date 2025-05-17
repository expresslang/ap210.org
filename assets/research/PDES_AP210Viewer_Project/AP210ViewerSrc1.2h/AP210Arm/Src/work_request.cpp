// Source for AP210 application object
//     work_request

// Precompiled include files
#include <StdAfx.h>

#include "work_request.h"

// Classes
#include <ee_approval.h>
#include <ee_text.h>

work_request::work_request() {
   initialize();
   }
work_request::~work_request() {
   // Free string attributes
   if (_work_request_id != NULL) {
      free(_work_request_id);
     }
   if (_status != NULL) {
      free(_status);
     }
   }
// intialize data members
void work_request::initialize() {
   // Required attributes
   _work_request_approval = NULL;
   _work_request_id = NULL;
   _description = NULL;
   _status = NULL;

   // Optional attributes
   }
// Runtime type identification
int work_request::DynamicType(int ID) {
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
work_request *work_request::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<work_request *>(s);
      }
   return NULL;
   }
work_request *work_request::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<work_request *>(s);
      }
   return NULL;
   }
// construction factory
work_request *work_request::Construct() {
   work_request *result = NULL;

   // create the work_request.
   result = new work_request();
   return result;
   }
bool work_request::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: work_request\r\n");

   // Check for the existence of all required attributes
   if (_work_request_approval == NULL) {
      TRACE("ERROR: _work_request_approval a required attribute is NULL!\r\n");
      result = false;
      }
   if (_request_recipient == NULL) {
      TRACE("ERROR: _request_recipient a required attribute is NULL!\r\n");
      result = false;
      }
   if (_work_request_id == NULL) {
      TRACE("ERROR: _work_request_id a required attribute is NULL!\r\n");
      result = false;
      }
   if (_referenced_product == NULL) {
      TRACE("ERROR: _referenced_product a required attribute is NULL!\r\n");
      result = false;
      }
   if (_request_date == NULL) {
      TRACE("ERROR: _request_date a required attribute is NULL!\r\n");
      result = false;
      }
   if (_description == NULL) {
      TRACE("ERROR: _description a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reason == NULL) {
      TRACE("ERROR: _reason a required attribute is NULL!\r\n");
      result = false;
      }
   if (_initiator == NULL) {
      TRACE("ERROR: _initiator a required attribute is NULL!\r\n");
      result = false;
      }
   if (_status == NULL) {
      TRACE("ERROR: _status a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
