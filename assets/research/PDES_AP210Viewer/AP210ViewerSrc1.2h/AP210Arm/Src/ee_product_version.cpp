// Source for AP210 application object
//     ee_product_version

// Precompiled include files
#include <StdAfx.h>

#include "ee_product_version.h"

// Classes
#include <contract.h>
#include <ee_product.h>
#include <security_classification.h>
#include <ee_approval.h>

ee_product_version::ee_product_version() {
   initialize();
   }
ee_product_version::~ee_product_version() {
   // Free string attributes
   if (_revision_code != NULL) {
      free(_revision_code);
     }
   }
// intialize data members
void ee_product_version::initialize() {
   // Required attributes
   _revision_code = NULL;
   _versioned_item = NULL;
   _security_code = NULL;
   _product_version_approval = NULL;

   // Optional attributes
   _authorizing_agreement = NULL;
   }
// Runtime type identification
int ee_product_version::DynamicType(int ID) {
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
ee_product_version *ee_product_version::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_product_version *>(s);
      }
   return NULL;
   }
ee_product_version *ee_product_version::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_product_version *>(s);
      }
   return NULL;
   }
// construction factory
ee_product_version *ee_product_version::Construct() {
   ee_product_version *result = NULL;

   // create the ee_product_version.
   result = new ee_product_version();
   return result;
   }
bool ee_product_version::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_product_version\r\n");

   // Check for the existence of all required attributes
   if (_creator == NULL) {
      TRACE("ERROR: _creator a required attribute is NULL!\r\n");
      result = false;
      }
   if (_revision_code == NULL) {
      TRACE("ERROR: _revision_code a required attribute is NULL!\r\n");
      result = false;
      }
   if (_versioned_item == NULL) {
      TRACE("ERROR: _versioned_item a required attribute is NULL!\r\n");
      result = false;
      }
   if (_security_code == NULL) {
      TRACE("ERROR: _security_code a required attribute is NULL!\r\n");
      result = false;
      }
   if (_product_version_approval == NULL) {
      TRACE("ERROR: _product_version_approval a required attribute is NULL!\r\n");
      result = false;
      }
   if (_life_cycle_status == NULL) {
      TRACE("ERROR: _life_cycle_status a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
