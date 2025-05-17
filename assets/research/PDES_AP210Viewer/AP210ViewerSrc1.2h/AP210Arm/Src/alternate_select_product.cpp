// Source for AP210 application object
//     alternate_select_product

// Precompiled include files
#include <StdAfx.h>

#include "alternate_select_product.h"

// Classes
#include <ee_product.h>
#include <contract.h>

alternate_select_product::alternate_select_product() {
   initialize();
   }
alternate_select_product::~alternate_select_product() {
   // Free string attributes
   }
// intialize data members
void alternate_select_product::initialize() {
   // Required attributes
   _defining_base_product = NULL;

   // Optional attributes
   _authorizing_agreement = NULL;
   }
// Runtime type identification
int alternate_select_product::DynamicType(int ID) {
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
alternate_select_product *alternate_select_product::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<alternate_select_product *>(s);
      }
   return NULL;
   }
alternate_select_product *alternate_select_product::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<alternate_select_product *>(s);
      }
   return NULL;
   }
// construction factory
alternate_select_product *alternate_select_product::Construct() {
   alternate_select_product *result = NULL;

   // create the alternate_select_product.
   result = new alternate_select_product();
   return result;
   }
bool alternate_select_product::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: alternate_select_product\r\n");

   // Check for the existence of all required attributes
   if (_defined_alternate_product == NULL) {
      TRACE("ERROR: _defined_alternate_product a required attribute is NULL!\r\n");
      result = false;
      }
   if (_defining_base_product == NULL) {
      TRACE("ERROR: _defining_base_product a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
