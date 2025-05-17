// Source for AP210 application object
//     physical_laminate_component

// Precompiled include files
#include <StdAfx.h>

#include "physical_laminate_component.h"

// Classes

physical_laminate_component::physical_laminate_component() {
   initialize();
   }
physical_laminate_component::~physical_laminate_component() {
   // Free string attributes
   }
// intialize data members
void physical_laminate_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int physical_laminate_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = laminate_component::DynamicType(ID);
      }
   if (result == 0) {
      result = physical_feature_or_part_template::DynamicType(ID);
      }
   return result;
   }
physical_laminate_component *physical_laminate_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_laminate_component *>(s);
      }
   return NULL;
   }
physical_laminate_component *physical_laminate_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_laminate_component *>(s);
      }
   return NULL;
   }
// construction factory
physical_laminate_component *physical_laminate_component::Construct() {
   physical_laminate_component *result = NULL;

   // create the physical_laminate_component.
   result = new physical_laminate_component();
   return result;
   }
bool physical_laminate_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_laminate_component\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   if (physical_feature_or_part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
