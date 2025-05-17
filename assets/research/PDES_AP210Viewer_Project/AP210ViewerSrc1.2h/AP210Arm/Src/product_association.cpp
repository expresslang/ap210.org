// Source for AP210 application object
//     product_association

// Precompiled include files
#include <StdAfx.h>

#include "product_association.h"

// Classes
#include <ee_product_version.h>
#include <ee_specification.h>

product_association::product_association() {
   initialize();
   }
product_association::~product_association() {
   // Free string attributes
   }
// intialize data members
void product_association::initialize() {
   // Required attributes
   _relating_product = NULL;
   _constraint_source = NULL;

   // Optional attributes
   }
// Runtime type identification
int product_association::DynamicType(int ID) {
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
product_association *product_association::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<product_association *>(s);
      }
   return NULL;
   }
product_association *product_association::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<product_association *>(s);
      }
   return NULL;
   }
// construction factory
product_association *product_association::Construct() {
   product_association *result = NULL;

   // create the product_association.
   result = new product_association();
   return result;
   }
bool product_association::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: product_association\r\n");

   // Check for the existence of all required attributes
   if (_relating_product == NULL) {
      TRACE("ERROR: _relating_product a required attribute is NULL!\r\n");
      result = false;
      }
   if (_related_product == NULL) {
      TRACE("ERROR: _related_product a required attribute is NULL!\r\n");
      result = false;
      }
   if (_constraint_source == NULL) {
      TRACE("ERROR: _constraint_source a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
