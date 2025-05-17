// Source for AP210 application object
//     externally_defined_ee_product_definition

// Precompiled include files
#include <StdAfx.h>

#include "externally_defined_ee_product_definition.h"

// Classes

externally_defined_ee_product_definition::externally_defined_ee_product_definition() {
   initialize();
   }
externally_defined_ee_product_definition::~externally_defined_ee_product_definition() {
   // Free string attributes
   if (_source != NULL) {
      free(_source);
     }
   }
// intialize data members
void externally_defined_ee_product_definition::initialize() {
   // Required attributes
   _source = NULL;

   // Optional attributes
   }
// Runtime type identification
int externally_defined_ee_product_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_product_definition::DynamicType(ID);
      }
   return result;
   }
externally_defined_ee_product_definition *externally_defined_ee_product_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<externally_defined_ee_product_definition *>(s);
      }
   return NULL;
   }
externally_defined_ee_product_definition *externally_defined_ee_product_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<externally_defined_ee_product_definition *>(s);
      }
   return NULL;
   }
// construction factory
externally_defined_ee_product_definition *externally_defined_ee_product_definition::Construct() {
   externally_defined_ee_product_definition *result = NULL;

   // create the externally_defined_ee_product_definition.
   result = new externally_defined_ee_product_definition();
   return result;
   }
bool externally_defined_ee_product_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: externally_defined_ee_product_definition\r\n");

   // Check for the existence of all required attributes
   if (_source == NULL) {
      TRACE("ERROR: _source a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (ee_product_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
