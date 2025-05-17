// Source for AP210 application object
//     assembly_technology_specification

// Precompiled include files
#include <StdAfx.h>

#include "assembly_technology_specification.h"

// Classes

assembly_technology_specification::assembly_technology_specification() {
   initialize();
   }
assembly_technology_specification::~assembly_technology_specification() {
   // Free string attributes
   }
// intialize data members
void assembly_technology_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int assembly_technology_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = process_specification::DynamicType(ID);
      }
   return result;
   }
assembly_technology_specification *assembly_technology_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_technology_specification *>(s);
      }
   return NULL;
   }
assembly_technology_specification *assembly_technology_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_technology_specification *>(s);
      }
   return NULL;
   }
// construction factory
assembly_technology_specification *assembly_technology_specification::Construct() {
   assembly_technology_specification *result = NULL;

   // create the assembly_technology_specification.
   result = new assembly_technology_specification();
   return result;
   }
bool assembly_technology_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_technology_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (process_specification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
