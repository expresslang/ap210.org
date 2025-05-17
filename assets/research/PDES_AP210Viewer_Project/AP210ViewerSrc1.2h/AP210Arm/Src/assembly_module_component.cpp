// Source for AP210 application object
//     assembly_module_component

// Precompiled include files
#include <StdAfx.h>

#include "assembly_module_component.h"

// Classes

assembly_module_component::assembly_module_component() {
   initialize();
   }
assembly_module_component::~assembly_module_component() {
   // Free string attributes
   }
// intialize data members
void assembly_module_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int assembly_module_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_component::DynamicType(ID);
      }
   return result;
   }
assembly_module_component *assembly_module_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_module_component *>(s);
      }
   return NULL;
   }
assembly_module_component *assembly_module_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_module_component *>(s);
      }
   return NULL;
   }
// construction factory
assembly_module_component *assembly_module_component::Construct() {
   assembly_module_component *result = NULL;

   // create the assembly_module_component.
   result = new assembly_module_component();
   return result;
   }
bool assembly_module_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_module_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
