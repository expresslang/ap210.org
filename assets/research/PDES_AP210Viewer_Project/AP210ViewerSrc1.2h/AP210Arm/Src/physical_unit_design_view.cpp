// Source for AP210 application object
//     physical_unit_design_view

// Precompiled include files
#include <StdAfx.h>

#include "physical_unit_design_view.h"

// Classes
#include <physical_unit_usage_view.h>

physical_unit_design_view::physical_unit_design_view() {
   initialize();
   }
physical_unit_design_view::~physical_unit_design_view() {
   // Free string attributes
   }
// intialize data members
void physical_unit_design_view::initialize() {
   // Required attributes
   _usage_view = NULL;

   // Optional attributes
   }
// Runtime type identification
int physical_unit_design_view::DynamicType(int ID) {
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
physical_unit_design_view *physical_unit_design_view::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_unit_design_view *>(s);
      }
   return NULL;
   }
physical_unit_design_view *physical_unit_design_view::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_unit_design_view *>(s);
      }
   return NULL;
   }
// construction factory
physical_unit_design_view *physical_unit_design_view::Construct() {
   physical_unit_design_view *result = NULL;

   // create the physical_unit_design_view.
   result = new physical_unit_design_view();
   return result;
   }
bool physical_unit_design_view::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_unit_design_view\r\n");

   // Check for the existence of all required attributes
   if (_usage_view == NULL) {
      TRACE("ERROR: _usage_view a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (physical_unit::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
