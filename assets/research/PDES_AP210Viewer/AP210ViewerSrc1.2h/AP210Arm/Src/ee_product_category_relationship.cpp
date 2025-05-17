// Source for AP210 application object
//     ee_product_category_relationship

// Precompiled include files
#include <StdAfx.h>

#include "ee_product_category_relationship.h"

// Classes
#include <ee_product_category.h>
#include <ee_product_category.h>

ee_product_category_relationship::ee_product_category_relationship() {
   initialize();
   }
ee_product_category_relationship::~ee_product_category_relationship() {
   // Free string attributes
   }
// intialize data members
void ee_product_category_relationship::initialize() {
   // Required attributes
   _sub_category = NULL;
   _category = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_product_category_relationship::DynamicType(int ID) {
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
ee_product_category_relationship *ee_product_category_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_product_category_relationship *>(s);
      }
   return NULL;
   }
ee_product_category_relationship *ee_product_category_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_product_category_relationship *>(s);
      }
   return NULL;
   }
// construction factory
ee_product_category_relationship *ee_product_category_relationship::Construct() {
   ee_product_category_relationship *result = NULL;

   // create the ee_product_category_relationship.
   result = new ee_product_category_relationship();
   return result;
   }
bool ee_product_category_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_product_category_relationship\r\n");

   // Check for the existence of all required attributes
   if (_sub_category == NULL) {
      TRACE("ERROR: _sub_category a required attribute is NULL!\r\n");
      result = false;
      }
   if (_category == NULL) {
      TRACE("ERROR: _category a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
