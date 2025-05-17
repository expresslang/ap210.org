// Source for AP210 application object
//     interface_specification

// Precompiled include files
#include <StdAfx.h>

#include "interface_specification.h"

// Classes

interface_specification::interface_specification() {
   initialize();
   }
interface_specification::~interface_specification() {
   // Free string attributes
   }
// intialize data members
void interface_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int interface_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = design_specification::DynamicType(ID);
      }
   return result;
   }
interface_specification *interface_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interface_specification *>(s);
      }
   return NULL;
   }
interface_specification *interface_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interface_specification *>(s);
      }
   return NULL;
   }
// construction factory
interface_specification *interface_specification::Construct() {
   interface_specification *result = NULL;

   // create the interface_specification.
   result = new interface_specification();
   return result;
   }
bool interface_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interface_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (design_specification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
