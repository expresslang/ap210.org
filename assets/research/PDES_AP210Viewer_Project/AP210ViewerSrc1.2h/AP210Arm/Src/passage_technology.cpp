// Source for AP210 application object
//     passage_technology

// Precompiled include files
#include <StdAfx.h>

#include "passage_technology.h"

// Classes
#include <inter_stratum_extent.h>
#include <ee_material.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <process_specification.h>

passage_technology::passage_technology() {
   initialize();
   }
passage_technology::~passage_technology() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void passage_technology::initialize() {
   // Required attributes
   _as_finished_inter_stratum_extent = NULL;
   _name = NULL;

   // Optional attributes
   _deposition_material = NULL;
   _maximum_as_finished_passage_extent = NULL;
   _minimum_as_finished_passage_extent = NULL;
   _maximum_as_finished_deposition_thickness = NULL;
   _minimum_as_finished_deposition_thickness = NULL;
   _specification = NULL;
   }
// Runtime type identification
int passage_technology::DynamicType(int ID) {
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
passage_technology *passage_technology::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<passage_technology *>(s);
      }
   return NULL;
   }
passage_technology *passage_technology::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<passage_technology *>(s);
      }
   return NULL;
   }
// construction factory
passage_technology *passage_technology::Construct() {
   passage_technology *result = NULL;

   // create the passage_technology.
   result = new passage_technology();
   return result;
   }
bool passage_technology::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: passage_technology\r\n");

   // Check for the existence of all required attributes
   if (_as_finished_inter_stratum_extent == NULL) {
      TRACE("ERROR: _as_finished_inter_stratum_extent a required attribute is NULL!\r\n");
      result = false;
      }
   if (_plated_passage == NULL) {
      TRACE("ERROR: _plated_passage a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
