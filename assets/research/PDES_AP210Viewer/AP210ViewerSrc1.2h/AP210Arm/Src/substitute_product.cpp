// Source for AP210 application object
//     substitute_product

// Precompiled include files
#include <StdAfx.h>

#include "substitute_product.h"

// Classes
#include <assembly_composition_relationship.h>

substitute_product::substitute_product() {
   initialize();
   }
substitute_product::~substitute_product() {
   // Free string attributes
   }
// intialize data members
void substitute_product::initialize() {
   // Required attributes
   _substitutable_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int substitute_product::DynamicType(int ID) {
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
substitute_product *substitute_product::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<substitute_product *>(s);
      }
   return NULL;
   }
substitute_product *substitute_product::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<substitute_product *>(s);
      }
   return NULL;
   }
// construction factory
substitute_product *substitute_product::Construct() {
   substitute_product *result = NULL;

   // create the substitute_product.
   result = new substitute_product();
   return result;
   }
bool substitute_product::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: substitute_product\r\n");

   // Check for the existence of all required attributes
   if (_defined_alternate_product == NULL) {
      TRACE("ERROR: _defined_alternate_product a required attribute is NULL!\r\n");
      result = false;
      }
   if (_substitutable_component == NULL) {
      TRACE("ERROR: _substitutable_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
