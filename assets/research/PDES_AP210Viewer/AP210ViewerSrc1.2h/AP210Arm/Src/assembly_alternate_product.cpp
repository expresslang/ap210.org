// Source for AP210 application object
//     assembly_alternate_product

// Precompiled include files
#include <StdAfx.h>

#include "assembly_alternate_product.h"

// Classes
#include <physical_unit_design_view.h>

assembly_alternate_product::assembly_alternate_product() {
   initialize();
   }
assembly_alternate_product::~assembly_alternate_product() {
   // Free string attributes
   }
// intialize data members
void assembly_alternate_product::initialize() {
   // Required attributes
   _basis_context = NULL;

   // Optional attributes
   }
// Runtime type identification
int assembly_alternate_product::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = alternate_select_product::DynamicType(ID);
      }
   return result;
   }
assembly_alternate_product *assembly_alternate_product::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_alternate_product *>(s);
      }
   return NULL;
   }
assembly_alternate_product *assembly_alternate_product::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_alternate_product *>(s);
      }
   return NULL;
   }
// construction factory
assembly_alternate_product *assembly_alternate_product::Construct() {
   assembly_alternate_product *result = NULL;

   // create the assembly_alternate_product.
   result = new assembly_alternate_product();
   return result;
   }
bool assembly_alternate_product::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_alternate_product\r\n");

   // Check for the existence of all required attributes
   if (_basis_context == NULL) {
      TRACE("ERROR: _basis_context a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (alternate_select_product::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
