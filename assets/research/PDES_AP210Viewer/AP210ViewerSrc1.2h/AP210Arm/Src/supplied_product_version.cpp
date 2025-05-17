// Source for AP210 application object
//     supplied_product_version

// Precompiled include files
#include <StdAfx.h>

#include "supplied_product_version.h"

// Classes
#include <ee_product_version.h>
#include <ee_approval.h>
#include <organization.h>

supplied_product_version::supplied_product_version() {
   initialize();
   }
supplied_product_version::~supplied_product_version() {
   // Free string attributes
   if (_supplier_part_number != NULL) {
      free(_supplier_part_number);
     }
   }
// intialize data members
void supplied_product_version::initialize() {
   // Required attributes
   _supplied_product_version = NULL;
   _supplied_product_version_approval = NULL;
   _supplier = NULL;

   // Optional attributes
   _supplier_part_number = NULL;
   }
// Runtime type identification
int supplied_product_version::DynamicType(int ID) {
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
supplied_product_version *supplied_product_version::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<supplied_product_version *>(s);
      }
   return NULL;
   }
supplied_product_version *supplied_product_version::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<supplied_product_version *>(s);
      }
   return NULL;
   }
// construction factory
supplied_product_version *supplied_product_version::Construct() {
   supplied_product_version *result = NULL;

   // create the supplied_product_version.
   result = new supplied_product_version();
   return result;
   }
bool supplied_product_version::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: supplied_product_version\r\n");

   // Check for the existence of all required attributes
   if (_supplied_product_version == NULL) {
      TRACE("ERROR: _supplied_product_version a required attribute is NULL!\r\n");
      result = false;
      }
   if (_supplied_product_version_approval == NULL) {
      TRACE("ERROR: _supplied_product_version_approval a required attribute is NULL!\r\n");
      result = false;
      }
   if (_supplier == NULL) {
      TRACE("ERROR: _supplier a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
