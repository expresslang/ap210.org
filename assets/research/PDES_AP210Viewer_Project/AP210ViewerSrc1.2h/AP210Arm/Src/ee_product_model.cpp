// Source for AP210 application object
//     ee_product_model

// Precompiled include files
#include <StdAfx.h>

#include "ee_product_model.h"

// Classes
#include <ee_text.h>

ee_product_model::ee_product_model() {
   initialize();
   }
ee_product_model::~ee_product_model() {
   // Free string attributes
   }
// intialize data members
void ee_product_model::initialize() {
   // Required attributes
   _model_name = NULL;

   // Optional attributes
   }
// Runtime type identification
int ee_product_model::DynamicType(int ID) {
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
ee_product_model *ee_product_model::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ee_product_model *>(s);
      }
   return NULL;
   }
ee_product_model *ee_product_model::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ee_product_model *>(s);
      }
   return NULL;
   }
// construction factory
ee_product_model *ee_product_model::Construct() {
   ee_product_model *result = NULL;

   // create the ee_product_model.
   result = new ee_product_model();
   return result;
   }
bool ee_product_model::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ee_product_model\r\n");

   // Check for the existence of all required attributes
   if (_model_name == NULL) {
      TRACE("ERROR: _model_name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
