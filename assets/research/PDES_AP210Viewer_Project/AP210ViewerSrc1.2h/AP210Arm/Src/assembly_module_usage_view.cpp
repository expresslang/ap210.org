// Source for AP210 application object
//     assembly_module_usage_view

// Precompiled include files
#include <StdAfx.h>

#include "assembly_module_usage_view.h"

// Classes
#include <functional_unit_usage_view.h>
#include <datum_based_length_measure.h>
#include <datum_based_length_measure.h>

assembly_module_usage_view::assembly_module_usage_view() {
   initialize();
   }
assembly_module_usage_view::~assembly_module_usage_view() {
   // Free string attributes
   }
// intialize data members
void assembly_module_usage_view::initialize() {
   // Required attributes
   _implemented_function = NULL;

   // Optional attributes
   _maximum_negative_component_height = NULL;
   _maximum_positive_component_height = NULL;
   }
// Runtime type identification
int assembly_module_usage_view::DynamicType(int ID) {
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
assembly_module_usage_view *assembly_module_usage_view::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_module_usage_view *>(s);
      }
   return NULL;
   }
assembly_module_usage_view *assembly_module_usage_view::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_module_usage_view *>(s);
      }
   return NULL;
   }
// construction factory
assembly_module_usage_view *assembly_module_usage_view::Construct() {
   assembly_module_usage_view *result = NULL;

   // create the assembly_module_usage_view.
   result = new assembly_module_usage_view();
   return result;
   }
bool assembly_module_usage_view::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_module_usage_view\r\n");

   // Check for the existence of all required attributes
   if (_implemented_function == NULL) {
      TRACE("ERROR: _implemented_function a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (physical_unit_usage_view::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
