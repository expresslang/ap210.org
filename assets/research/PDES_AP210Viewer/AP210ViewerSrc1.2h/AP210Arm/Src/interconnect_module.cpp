// Source for AP210 application object
//     interconnect_module

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module.h"

// Classes

interconnect_module::interconnect_module() {
   initialize();
   }
interconnect_module::~interconnect_module() {
   // Free string attributes
   }
// intialize data members
void interconnect_module::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interconnect_module::DynamicType(int ID) {
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
interconnect_module *interconnect_module::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module *>(s);
      }
   return NULL;
   }
interconnect_module *interconnect_module::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module *interconnect_module::Construct() {
   interconnect_module *result = NULL;

   // create the interconnect_module.
   result = new interconnect_module();
   return result;
   }
bool interconnect_module::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (physical_unit_design_view::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
