// Source for AP210 application object
//     library_model

// Precompiled include files
#include <StdAfx.h>

#include "library_model.h"

// Classes

library_model::library_model() {
   initialize();
   }
library_model::~library_model() {
   // Free string attributes
   }
// intialize data members
void library_model::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int library_model::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = library_ee_product_definition::DynamicType(ID);
      }
   if (result == 0) {
      result = analytical_model::DynamicType(ID);
      }
   return result;
   }
library_model *library_model::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<library_model *>(s);
      }
   return NULL;
   }
library_model *library_model::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<library_model *>(s);
      }
   return NULL;
   }
// construction factory
library_model *library_model::Construct() {
   library_model *result = NULL;

   // create the library_model.
   result = new library_model();
   return result;
   }
bool library_model::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: library_model\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (library_ee_product_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   if (analytical_model::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
