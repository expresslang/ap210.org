// Source for AP210 application object
//     stratum_technology

// Precompiled include files
#include <StdAfx.h>

#include "stratum_technology.h"

// Classes
#include <ee_material.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <length_data_element.h>
#include <process_specification.h>

stratum_technology::stratum_technology() {
   initialize();
   }
stratum_technology::~stratum_technology() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void stratum_technology::initialize() {
   // Required attributes
   _stratum_material = NULL;
   _maximum_stratum_thickness = NULL;
   _minimum_stratum_thickness = NULL;
   _name = NULL;

   // Optional attributes
   _minimum_finished_feature_size = NULL;
   _minimum_finished_feature_spacing = NULL;
   _maximum_feature_size_requirement = NULL;
   _specification = NULL;
   }
// Runtime type identification
int stratum_technology::DynamicType(int ID) {
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
stratum_technology *stratum_technology::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_technology *>(s);
      }
   return NULL;
   }
stratum_technology *stratum_technology::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_technology *>(s);
      }
   return NULL;
   }
// construction factory
stratum_technology *stratum_technology::Construct() {
   stratum_technology *result = NULL;

   // create the stratum_technology.
   result = new stratum_technology();
   return result;
   }
bool stratum_technology::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_technology\r\n");

   // Check for the existence of all required attributes
   if (_stratum_material == NULL) {
      TRACE("ERROR: _stratum_material a required attribute is NULL!\r\n");
      result = false;
      }
   if (_maximum_stratum_thickness == NULL) {
      TRACE("ERROR: _maximum_stratum_thickness a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minimum_stratum_thickness == NULL) {
      TRACE("ERROR: _minimum_stratum_thickness a required attribute is NULL!\r\n");
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
