// Source for AP210 application object
//     work_order

// Precompiled include files
#include <StdAfx.h>

#include "work_order.h"

// Classes
#include <ee_text.h>
#include <ee_text.h>
#include <ee_approval.h>
#include <contract.h>

work_order::work_order() {
   initialize();
   }
work_order::~work_order() {
   // Free string attributes
   if (_work_order_id != NULL) {
      free(_work_order_id);
     }
   }
// intialize data members
void work_order::initialize() {
   // Required attributes
   _work_order_id = NULL;
   _work_order_approval = NULL;

   // Optional attributes
   _analysis_data = NULL;
   _additional_data = NULL;
   _authorizing_agreement = NULL;
   }
// Runtime type identification
int work_order::DynamicType(int ID) {
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
work_order *work_order::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<work_order *>(s);
      }
   return NULL;
   }
work_order *work_order::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<work_order *>(s);
      }
   return NULL;
   }
// construction factory
work_order *work_order::Construct() {
   work_order *result = NULL;

   // create the work_order.
   result = new work_order();
   return result;
   }
bool work_order::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: work_order\r\n");

   // Check for the existence of all required attributes
   if (_referenced_work_request == NULL) {
      TRACE("ERROR: _referenced_work_request a required attribute is NULL!\r\n");
      result = false;
      }
   if (_work_order_id == NULL) {
      TRACE("ERROR: _work_order_id a required attribute is NULL!\r\n");
      result = false;
      }
   if (_resulting_product == NULL) {
      TRACE("ERROR: _resulting_product a required attribute is NULL!\r\n");
      result = false;
      }
   if (_work_order_approval == NULL) {
      TRACE("ERROR: _work_order_approval a required attribute is NULL!\r\n");
      result = false;
      }
   if (_initiator == NULL) {
      TRACE("ERROR: _initiator a required attribute is NULL!\r\n");
      result = false;
      }
   if (_start_date == NULL) {
      TRACE("ERROR: _start_date a required attribute is NULL!\r\n");
      result = false;
      }
   if (_release_date == NULL) {
      TRACE("ERROR: _release_date a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
