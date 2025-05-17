// Source for AP210 application object
//     located_interconnect_module_thickness_requirement

// Precompiled include files
#include <StdAfx.h>

#include "located_interconnect_module_thickness_requirement.h"

// Classes
#include <axis_placement.h>
#include <length_data_element.h>
#include <length_data_element.h>

located_interconnect_module_thickness_requirement::located_interconnect_module_thickness_requirement() {
   initialize();
   }
located_interconnect_module_thickness_requirement::~located_interconnect_module_thickness_requirement() {
   // Free string attributes
   }
// intialize data members
void located_interconnect_module_thickness_requirement::initialize() {
   // Required attributes
   _reference_location = NULL;
   _maximum_thickness_requirement = NULL;
   _minimum_thickness_requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int located_interconnect_module_thickness_requirement::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
located_interconnect_module_thickness_requirement *located_interconnect_module_thickness_requirement::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<located_interconnect_module_thickness_requirement *>(s);
      }
   return NULL;
   }
located_interconnect_module_thickness_requirement *located_interconnect_module_thickness_requirement::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<located_interconnect_module_thickness_requirement *>(s);
      }
   return NULL;
   }
// construction factory
located_interconnect_module_thickness_requirement *located_interconnect_module_thickness_requirement::Construct() {
   located_interconnect_module_thickness_requirement *result = NULL;

   // create the located_interconnect_module_thickness_requirement.
   result = new located_interconnect_module_thickness_requirement();
   return result;
   }
bool located_interconnect_module_thickness_requirement::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: located_interconnect_module_thickness_requirement\r\n");

   // Check for the existence of all required attributes
   if (_reference_location == NULL) {
      TRACE("ERROR: _reference_location a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_thickness_requirement == NULL) {
      TRACE("ERROR: _maximum_thickness_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_thickness_requirement == NULL) {
      TRACE("ERROR: _minimum_thickness_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
