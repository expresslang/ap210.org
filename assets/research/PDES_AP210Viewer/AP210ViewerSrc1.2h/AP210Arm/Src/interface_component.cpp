// Source for AP210 application object
//     interface_component

// Precompiled include files
#include <StdAfx.h>

#include "interface_component.h"

// Classes

interface_component::interface_component() {
   initialize();
   }
interface_component::~interface_component() {
   // Free string attributes
   }
// intialize data members
void interface_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interface_component::DynamicType(int ID) {
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
interface_component *interface_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interface_component *>(s);
      }
   return NULL;
   }
interface_component *interface_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interface_component *>(s);
      }
   return NULL;
   }
// construction factory
interface_component *interface_component::Construct() {
   interface_component *result = NULL;

   // create the interface_component.
   result = new interface_component();
   return result;
   }
bool interface_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interface_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
