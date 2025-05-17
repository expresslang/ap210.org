// Source for AP210 application object
//     evaluated_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "evaluated_characteristic.h"

// Classes
#include <planned_characteristic.h>

evaluated_characteristic::evaluated_characteristic() {
   initialize();
   }
evaluated_characteristic::~evaluated_characteristic() {
   // Free string attributes
   }
// intialize data members
void evaluated_characteristic::initialize() {
   // Required attributes
   _evaluated_product_data = NULL;

   // Optional attributes
   }
// Runtime type identification
int evaluated_characteristic::DynamicType(int ID) {
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
evaluated_characteristic *evaluated_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<evaluated_characteristic *>(s);
      }
   return NULL;
   }
evaluated_characteristic *evaluated_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<evaluated_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
evaluated_characteristic *evaluated_characteristic::Construct() {
   evaluated_characteristic *result = NULL;

   // create the evaluated_characteristic.
   result = new evaluated_characteristic();
   return result;
   }
bool evaluated_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: evaluated_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_evaluated_product_data == NULL) {
      TRACE("ERROR: _evaluated_product_data a required attribute is NULL!\r\n");
      result = false;
      }
   if (_product_data_status == NULL) {
      TRACE("ERROR: _product_data_status a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
