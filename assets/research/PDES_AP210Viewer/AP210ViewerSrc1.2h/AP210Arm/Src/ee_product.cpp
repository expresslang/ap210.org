// Source for AP210 application object
//     ee_product

// Precompiled include files
#include <StdAfx.h>

#include "ee_product.h"

// Classes

ee_product::ee_product() {
   initialize();
   }
ee_product::~ee_product() {
   // Free string attributes
   if (_product_nomenclature != NULL) {
      free(_product_nomenclature);
     }
   if (_part_number != NULL) {
      free(_part_number);
     }
   }
// intialize data members
void ee_product::initialize() {
   // Required attributes
   _product_nomenclature = NULL;
   _part_number = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_product::DynamicType(int ID) {
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
ee_product *ee_product::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_product *>(s);
      }
   return NULL;
   }
ee_product *ee_product::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_product *>(s);
      }
   return NULL;
   }
// construction factory
ee_product *ee_product::Construct() {
   ee_product *result = NULL;

   // create the ee_product.
   result = new ee_product();
   return result;
   }
bool ee_product::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_product\r\n");

   // Check for the existence of all required attributes
   if (_product_nomenclature == NULL) {
      TRACE("ERROR: _product_nomenclature a required attribute is NULL!\r\n");
      result = false;
      }
   if (_part_number == NULL) {
      TRACE("ERROR: _part_number a required attribute is NULL!\r\n");
      result = false;
      }
   if (_design_owner == NULL) {
      TRACE("ERROR: _design_owner a required attribute is NULL!\r\n");
      result = false;
      }
   if (_standard_product_indicator == NULL) {
      TRACE("ERROR: _standard_product_indicator a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
