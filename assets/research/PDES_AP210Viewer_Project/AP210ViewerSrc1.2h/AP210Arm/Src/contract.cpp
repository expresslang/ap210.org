// Source for AP210 application object
//     contract

// Precompiled include files
#include <StdAfx.h>

#include "contract.h"

// Classes
#include <ee_text.h>
#include <ee_approval.h>

contract::contract() {
   initialize();
   }
contract::~contract() {
   // Free string attributes
   }
// intialize data members
void contract::initialize() {
   // Required attributes
   _contract_number = NULL;
   _contract_approval = NULL;

   // Optional attributes
   }
// Runtime type identification
int contract::DynamicType(int ID) {
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
contract *contract::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<contract *>(s);
      }
   return NULL;
   }
contract *contract::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<contract *>(s);
      }
   return NULL;
   }
// construction factory
contract *contract::Construct() {
   contract *result = NULL;

   // create the contract.
   result = new contract();
   return result;
   }
bool contract::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: contract\r\n");

   // Check for the existence of all required attributes
   if (_contract_number == NULL) {
      TRACE("ERROR: _contract_number a required attribute is NULL!\r\n");
      result = false;
      }
   if (_contract_approval == NULL) {
      TRACE("ERROR: _contract_approval a required attribute is NULL!\r\n");
      result = false;
      }
   if (_contract_date == NULL) {
      TRACE("ERROR: _contract_date a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
