// Source for AP210 application object
//     interconnect_module_component

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_component.h"

// Classes

interconnect_module_component::interconnect_module_component() {
   initialize();
   }
interconnect_module_component::~interconnect_module_component() {
   // Free string attributes
   }
// intialize data members
void interconnect_module_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interconnect_module_component::DynamicType(int ID) {
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
interconnect_module_component *interconnect_module_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_component *>(s);
      }
   return NULL;
   }
interconnect_module_component *interconnect_module_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_component *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_component *interconnect_module_component::Construct() {
   interconnect_module_component *result = NULL;

   // create the interconnect_module_component.
   result = new interconnect_module_component();
   return result;
   }
bool interconnect_module_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
