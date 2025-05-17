// Source for AP210 application object
//     interconnect_module_usage_view

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_usage_view.h"

// Classes
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <restraint_condition.h>
#include <located_interconnect_module_thickness_requirement.h>
#include <functional_unit_usage_view.h>

interconnect_module_usage_view::interconnect_module_usage_view() {
   initialize();
   }
interconnect_module_usage_view::~interconnect_module_usage_view() {
   // Free string attributes
   }
// intialize data members
void interconnect_module_usage_view::initialize() {
   // Required attributes

   // Optional attributes
   _minimum_thickness_over_metal_requirement = NULL;
   _maximum_thickness_over_metal_requirement = NULL;
   _minimum_thickness_over_dielectric_requirement = NULL;
   _maximum_thickness_over_dielectric_requirement = NULL;
   _measurement_condition = NULL;
   _located_thickness_requirement = NULL;
   _implemented_function = NULL;
   }
// Runtime type identification
int interconnect_module_usage_view::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = physical_unit_usage_view::DynamicType(ID);
      }
   return result;
   }
interconnect_module_usage_view *interconnect_module_usage_view::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_usage_view *>(s);
      }
   return NULL;
   }
interconnect_module_usage_view *interconnect_module_usage_view::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_usage_view *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_usage_view *interconnect_module_usage_view::Construct() {
   interconnect_module_usage_view *result = NULL;

   // create the interconnect_module_usage_view.
   result = new interconnect_module_usage_view();
   return result;
   }
bool interconnect_module_usage_view::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_usage_view\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (physical_unit_usage_view::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
