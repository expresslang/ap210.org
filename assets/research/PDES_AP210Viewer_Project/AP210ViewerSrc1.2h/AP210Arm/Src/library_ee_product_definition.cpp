// Source for AP210 application object
//     library_ee_product_definition

// Precompiled include files
#include <StdAfx.h>

#include "library_ee_product_definition.h"

// Classes

library_ee_product_definition::library_ee_product_definition() {
   initialize();
   }
library_ee_product_definition::~library_ee_product_definition() {
   // Free string attributes
   }
// intialize data members
void library_ee_product_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int library_ee_product_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = library_item::DynamicType(ID);
      }
   if (result == 0) {
      result = ee_product_definition::DynamicType(ID);
      }
   return result;
   }
library_ee_product_definition *library_ee_product_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<library_ee_product_definition *>(s);
      }
   return NULL;
   }
library_ee_product_definition *library_ee_product_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<library_ee_product_definition *>(s);
      }
   return NULL;
   }
// construction factory
library_ee_product_definition *library_ee_product_definition::Construct() {
   library_ee_product_definition *result = NULL;

   // create the library_ee_product_definition.
   result = new library_ee_product_definition();
   return result;
   }
bool library_ee_product_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: library_ee_product_definition\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (library_item::hasRequiredAttributes() == false) {
      result = false;
      }
   if (ee_product_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
