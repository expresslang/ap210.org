// Source for AP210 application object
//     physical_unit

// Precompiled include files
#include <StdAfx.h>

#include "physical_unit.h"

// Classes
#include <technology.h>

physical_unit::physical_unit() {
   initialize();
   }
physical_unit::~physical_unit() {
   // Free string attributes
   }
// intialize data members
void physical_unit::initialize() {
   // Required attributes

   // Optional attributes
   _unit_technology = NULL;
   }
// Runtime type identification
int physical_unit::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_product_definition::DynamicType(ID);
      }
   return result;
   }
physical_unit *physical_unit::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_unit *>(s);
      }
   return NULL;
   }
physical_unit *physical_unit::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_unit *>(s);
      }
   return NULL;
   }
// construction factory
physical_unit *physical_unit::Construct() {
   physical_unit *result = NULL;

   // create the physical_unit.
   result = new physical_unit();
   return result;
   }
bool physical_unit::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_unit\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_product_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
