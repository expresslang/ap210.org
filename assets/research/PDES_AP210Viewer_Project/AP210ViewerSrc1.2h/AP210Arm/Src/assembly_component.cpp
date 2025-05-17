// Source for AP210 application object
//     assembly_component

// Precompiled include files
#include <StdAfx.h>

#include "assembly_component.h"

// Classes

assembly_component::assembly_component() {
   initialize();
   }
assembly_component::~assembly_component() {
   // Free string attributes
   }
// intialize data members
void assembly_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int assembly_component::DynamicType(int ID) {
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
assembly_component *assembly_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_component *>(s);
      }
   return NULL;
   }
assembly_component *assembly_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_component *>(s);
      }
   return NULL;
   }
// construction factory
assembly_component *assembly_component::Construct() {
   assembly_component *result = NULL;

   // create the assembly_component.
   result = new assembly_component();
   return result;
   }
bool assembly_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
