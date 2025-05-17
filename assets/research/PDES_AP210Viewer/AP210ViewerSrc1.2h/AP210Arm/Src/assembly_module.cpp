// Source for AP210 application object
//     assembly_module

// Precompiled include files
#include <StdAfx.h>

#include "assembly_module.h"

// Classes

assembly_module::assembly_module() {
   initialize();
   }
assembly_module::~assembly_module() {
   // Free string attributes
   }
// intialize data members
void assembly_module::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int assembly_module::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = physical_unit_design_view::DynamicType(ID);
      }
   return result;
   }
assembly_module *assembly_module::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_module *>(s);
      }
   return NULL;
   }
assembly_module *assembly_module::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_module *>(s);
      }
   return NULL;
   }
// construction factory
assembly_module *assembly_module::Construct() {
   assembly_module *result = NULL;

   // create the assembly_module.
   result = new assembly_module();
   return result;
   }
bool assembly_module::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_module\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (physical_unit_design_view::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
