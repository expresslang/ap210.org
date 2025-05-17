// Source for AP210 application object
//     ee_product_configuration

// Precompiled include files
#include <StdAfx.h>

#include "ee_product_configuration.h"

// Classes
#include <ee_approval.h>
#include <ee_product_model.h>

ee_product_configuration::ee_product_configuration() {
   initialize();
   }
ee_product_configuration::~ee_product_configuration() {
   // Free string attributes
   if (_item_id != NULL) {
      free(_item_id);
     }
   if (_phase_of_product != NULL) {
      free(_phase_of_product);
     }
   }
// intialize data members
void ee_product_configuration::initialize() {
   // Required attributes
   _item_id = NULL;
   _product_configuration_approval = NULL;
   _model_of_product = NULL;
   _phase_of_product = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_product_configuration::DynamicType(int ID) {
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
ee_product_configuration *ee_product_configuration::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_product_configuration *>(s);
      }
   return NULL;
   }
ee_product_configuration *ee_product_configuration::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_product_configuration *>(s);
      }
   return NULL;
   }
// construction factory
ee_product_configuration *ee_product_configuration::Construct() {
   ee_product_configuration *result = NULL;

   // create the ee_product_configuration.
   result = new ee_product_configuration();
   return result;
   }
bool ee_product_configuration::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_product_configuration\r\n");

   // Check for the existence of all required attributes
   if (_configuration_manager == NULL) {
      TRACE("ERROR: _configuration_manager a required attribute is NULL!\r\n");
      result = false;
      }
   if (_item_id == NULL) {
      TRACE("ERROR: _item_id a required attribute is NULL!\r\n");
      result = false;
      }
   if (_product_configuration_approval == NULL) {
      TRACE("ERROR: _product_configuration_approval a required attribute is NULL!\r\n");
      result = false;
      }
   if (_model_of_product == NULL) {
      TRACE("ERROR: _model_of_product a required attribute is NULL!\r\n");
      result = false;
      }
   if (_phase_of_product == NULL) {
      TRACE("ERROR: _phase_of_product a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
