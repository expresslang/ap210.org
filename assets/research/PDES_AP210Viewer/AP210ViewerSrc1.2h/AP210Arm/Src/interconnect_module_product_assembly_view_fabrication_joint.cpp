// Source for AP210 application object
//     interconnect_module_product_assembly_view_fabrication_joint

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_product_assembly_view_fabrication_joint.h"

// Classes

interconnect_module_product_assembly_view_fabrication_joint::interconnect_module_product_assembly_view_fabrication_joint() {
   initialize();
   }
interconnect_module_product_assembly_view_fabrication_joint::~interconnect_module_product_assembly_view_fabrication_joint() {
   // Free string attributes
   }
// intialize data members
void interconnect_module_product_assembly_view_fabrication_joint::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interconnect_module_product_assembly_view_fabrication_joint::DynamicType(int ID) {
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
interconnect_module_product_assembly_view_fabrication_joint *interconnect_module_product_assembly_view_fabrication_joint::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_product_assembly_view_fabrication_joint *>(s);
      }
   return NULL;
   }
interconnect_module_product_assembly_view_fabrication_joint *interconnect_module_product_assembly_view_fabrication_joint::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_product_assembly_view_fabrication_joint *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_product_assembly_view_fabrication_joint *interconnect_module_product_assembly_view_fabrication_joint::Construct() {
   interconnect_module_product_assembly_view_fabrication_joint *result = NULL;

   // create the interconnect_module_product_assembly_view_fabrication_joint.
   result = new interconnect_module_product_assembly_view_fabrication_joint();
   return result;
   }
bool interconnect_module_product_assembly_view_fabrication_joint::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_product_assembly_view_fabrication_joint\r\n");

   // Check for the existence of all required attributes
   if (_joined_terminal == NULL) {
      TRACE("ERROR: _joined_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
