// Source for AP210 application object
//     ee_product_specific_parameter_value_assignment

// Precompiled include files
#include <StdAfx.h>

#include "ee_product_specific_parameter_value_assignment.h"

// Classes
#include <ee_product_related_product_category.h>
#include <ee_product.h>
#include <parameter_assignment.h>

ee_product_specific_parameter_value_assignment::ee_product_specific_parameter_value_assignment() {
   initialize();
   }
ee_product_specific_parameter_value_assignment::~ee_product_specific_parameter_value_assignment() {
   // Free string attributes
   }
// intialize data members
void ee_product_specific_parameter_value_assignment::initialize() {
   // Required attributes
   _associated_product_category = NULL;
   _of_product = NULL;
   _assigned_parameter = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_product_specific_parameter_value_assignment::DynamicType(int ID) {
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
ee_product_specific_parameter_value_assignment *ee_product_specific_parameter_value_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_product_specific_parameter_value_assignment *>(s);
      }
   return NULL;
   }
ee_product_specific_parameter_value_assignment *ee_product_specific_parameter_value_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_product_specific_parameter_value_assignment *>(s);
      }
   return NULL;
   }
// construction factory
ee_product_specific_parameter_value_assignment *ee_product_specific_parameter_value_assignment::Construct() {
   ee_product_specific_parameter_value_assignment *result = NULL;

   // create the ee_product_specific_parameter_value_assignment.
   result = new ee_product_specific_parameter_value_assignment();
   return result;
   }
bool ee_product_specific_parameter_value_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_product_specific_parameter_value_assignment\r\n");

   // Check for the existence of all required attributes
   if (_associated_product_category == NULL) {
      TRACE("ERROR: _associated_product_category a required attribute is NULL!\r\n");
      result = false;
      }
   if (_of_product == NULL) {
      TRACE("ERROR: _of_product a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_parameter == NULL) {
      TRACE("ERROR: _assigned_parameter a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
