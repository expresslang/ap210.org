// Source for AP210 application object
//     physical_connectivity_structure_definition

// Precompiled include files
#include <StdAfx.h>

#include "physical_connectivity_structure_definition.h"

// Classes

physical_connectivity_structure_definition::physical_connectivity_structure_definition() {
   initialize();
   }
physical_connectivity_structure_definition::~physical_connectivity_structure_definition() {
   // Free string attributes
   }
// intialize data members
void physical_connectivity_structure_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int physical_connectivity_structure_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = physical_connectivity_definition::DynamicType(ID);
      }
   return result;
   }
physical_connectivity_structure_definition *physical_connectivity_structure_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_connectivity_structure_definition *>(s);
      }
   return NULL;
   }
physical_connectivity_structure_definition *physical_connectivity_structure_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_connectivity_structure_definition *>(s);
      }
   return NULL;
   }
// construction factory
physical_connectivity_structure_definition *physical_connectivity_structure_definition::Construct() {
   physical_connectivity_structure_definition *result = NULL;

   // create the physical_connectivity_structure_definition.
   result = new physical_connectivity_structure_definition();
   return result;
   }
bool physical_connectivity_structure_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_connectivity_structure_definition\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (physical_connectivity_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
