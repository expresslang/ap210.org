// Source for AP210 application object
//     ee_product_category

// Precompiled include files
#include <StdAfx.h>

#include "ee_product_category.h"

// Classes
#include <ee_document.h>

ee_product_category::ee_product_category() {
   initialize();
   }
ee_product_category::~ee_product_category() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void ee_product_category::initialize() {
   // Required attributes
   _name = NULL;

   // Optional attributes
   _reference_document = NULL;
   }
// Runtime type identification
int ee_product_category::DynamicType(int ID) {
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
ee_product_category *ee_product_category::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_product_category *>(s);
      }
   return NULL;
   }
ee_product_category *ee_product_category::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_product_category *>(s);
      }
   return NULL;
   }
// construction factory
ee_product_category *ee_product_category::Construct() {
   ee_product_category *result = NULL;

   // create the ee_product_category.
   result = new ee_product_category();
   return result;
   }
bool ee_product_category::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_product_category\r\n");

   // Check for the existence of all required attributes
   if (_category_parameter == NULL) {
      TRACE("ERROR: _category_parameter a required attribute is NULL!\r\n");
      result = false;
      }
   if (_category_specific_values == NULL) {
      TRACE("ERROR: _category_specific_values a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
