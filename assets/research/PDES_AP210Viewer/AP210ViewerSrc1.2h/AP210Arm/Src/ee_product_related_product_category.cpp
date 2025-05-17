// Source for AP210 application object
//     ee_product_related_product_category

// Precompiled include files
#include <StdAfx.h>

#include "ee_product_related_product_category.h"

// Classes

ee_product_related_product_category::ee_product_related_product_category() {
   initialize();
   }
ee_product_related_product_category::~ee_product_related_product_category() {
   // Free string attributes
   }
// intialize data members
void ee_product_related_product_category::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int ee_product_related_product_category::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_product_category::DynamicType(ID);
      }
   return result;
   }
ee_product_related_product_category *ee_product_related_product_category::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_product_related_product_category *>(s);
      }
   return NULL;
   }
ee_product_related_product_category *ee_product_related_product_category::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_product_related_product_category *>(s);
      }
   return NULL;
   }
// construction factory
ee_product_related_product_category *ee_product_related_product_category::Construct() {
   ee_product_related_product_category *result = NULL;

   // create the ee_product_related_product_category.
   result = new ee_product_related_product_category();
   return result;
   }
bool ee_product_related_product_category::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_product_related_product_category\r\n");

   // Check for the existence of all required attributes
   if (_of_product == NULL) {
      TRACE("ERROR: _of_product a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (ee_product_category::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
