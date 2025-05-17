// Source for AP210 application object
//     stratum_technology_line_width_tolerance_assignment

// Precompiled include files
#include <StdAfx.h>

#include "stratum_technology_line_width_tolerance_assignment.h"

// Classes
#include <stratum_technology.h>
#include <line_width_class.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <interconnect_module.h>

stratum_technology_line_width_tolerance_assignment::stratum_technology_line_width_tolerance_assignment() {
   initialize();
   }
stratum_technology_line_width_tolerance_assignment::~stratum_technology_line_width_tolerance_assignment() {
   // Free string attributes
   }
// intialize data members
void stratum_technology_line_width_tolerance_assignment::initialize() {
   // Required attributes
   _characterized_stratum_technology = NULL;
   _tolerance_line_width_class = NULL;
   _maximum_negative_deviation = NULL;
   _maximum_positive_deviation = NULL;
   _design_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_technology_line_width_tolerance_assignment::DynamicType(int ID) {
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
stratum_technology_line_width_tolerance_assignment *stratum_technology_line_width_tolerance_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_technology_line_width_tolerance_assignment *>(s);
      }
   return NULL;
   }
stratum_technology_line_width_tolerance_assignment *stratum_technology_line_width_tolerance_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_technology_line_width_tolerance_assignment *>(s);
      }
   return NULL;
   }
// construction factory
stratum_technology_line_width_tolerance_assignment *stratum_technology_line_width_tolerance_assignment::Construct() {
   stratum_technology_line_width_tolerance_assignment *result = NULL;

   // create the stratum_technology_line_width_tolerance_assignment.
   result = new stratum_technology_line_width_tolerance_assignment();
   return result;
   }
bool stratum_technology_line_width_tolerance_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_technology_line_width_tolerance_assignment\r\n");

   // Check for the existence of all required attributes
   if (_characterized_stratum_technology == NULL) {
      TRACE("ERROR: _characterized_stratum_technology a required attribute is NULL!\r\n");
      result = false;
      }
   if (_tolerance_line_width_class == NULL) {
      TRACE("ERROR: _tolerance_line_width_class a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_negative_deviation == NULL) {
      TRACE("ERROR: _maximum_negative_deviation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_positive_deviation == NULL) {
      TRACE("ERROR: _maximum_positive_deviation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_design_definition == NULL) {
      TRACE("ERROR: _design_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
