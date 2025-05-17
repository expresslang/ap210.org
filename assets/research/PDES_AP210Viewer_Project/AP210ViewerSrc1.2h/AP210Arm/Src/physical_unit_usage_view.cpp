// Source for AP210 application object
//     physical_unit_usage_view

// Precompiled include files
#include <StdAfx.h>

#include "physical_unit_usage_view.h"

// Classes

physical_unit_usage_view::physical_unit_usage_view() {
   initialize();
   }
physical_unit_usage_view::~physical_unit_usage_view() {
   // Free string attributes
   }
// intialize data members
void physical_unit_usage_view::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int physical_unit_usage_view::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = physical_unit::DynamicType(ID);
      }
   return result;
   }
physical_unit_usage_view *physical_unit_usage_view::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_unit_usage_view *>(s);
      }
   return NULL;
   }
physical_unit_usage_view *physical_unit_usage_view::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_unit_usage_view *>(s);
      }
   return NULL;
   }
// construction factory
physical_unit_usage_view *physical_unit_usage_view::Construct() {
   physical_unit_usage_view *result = NULL;

   // create the physical_unit_usage_view.
   result = new physical_unit_usage_view();
   return result;
   }
bool physical_unit_usage_view::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_unit_usage_view\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (physical_unit::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
