// Source for AP210 application object
//     fabrication_technology_specification

// Precompiled include files
#include <StdAfx.h>

#include "fabrication_technology_specification.h"

// Classes

fabrication_technology_specification::fabrication_technology_specification() {
   initialize();
   }
fabrication_technology_specification::~fabrication_technology_specification() {
   // Free string attributes
   }
// intialize data members
void fabrication_technology_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int fabrication_technology_specification::DynamicType(int ID) {
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
fabrication_technology_specification *fabrication_technology_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fabrication_technology_specification *>(s);
      }
   return NULL;
   }
fabrication_technology_specification *fabrication_technology_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fabrication_technology_specification *>(s);
      }
   return NULL;
   }
// construction factory
fabrication_technology_specification *fabrication_technology_specification::Construct() {
   fabrication_technology_specification *result = NULL;

   // create the fabrication_technology_specification.
   result = new fabrication_technology_specification();
   return result;
   }
bool fabrication_technology_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fabrication_technology_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (process_specification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
