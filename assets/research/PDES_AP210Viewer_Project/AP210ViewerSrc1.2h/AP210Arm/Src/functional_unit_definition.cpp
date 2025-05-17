// Source for AP210 application object
//     functional_unit_definition

// Precompiled include files
#include <StdAfx.h>

#include "functional_unit_definition.h"

// Classes

functional_unit_definition::functional_unit_definition() {
   initialize();
   }
functional_unit_definition::~functional_unit_definition() {
   // Free string attributes
   if (_ee_function != NULL) {
      free(_ee_function);
     }
   }
// intialize data members
void functional_unit_definition::initialize() {
   // Required attributes
   _ee_function = NULL;

   // Optional attributes
   }
// Runtime type identification
int functional_unit_definition::DynamicType(int ID) {
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
functional_unit_definition *functional_unit_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_unit_definition *>(s);
      }
   return NULL;
   }
functional_unit_definition *functional_unit_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_unit_definition *>(s);
      }
   return NULL;
   }
// construction factory
functional_unit_definition *functional_unit_definition::Construct() {
   functional_unit_definition *result = NULL;

   // create the functional_unit_definition.
   result = new functional_unit_definition();
   return result;
   }
bool functional_unit_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_unit_definition\r\n");

   // Check for the existence of all required attributes
   if (_ee_function == NULL) {
      TRACE("ERROR: _ee_function a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (ee_product_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
