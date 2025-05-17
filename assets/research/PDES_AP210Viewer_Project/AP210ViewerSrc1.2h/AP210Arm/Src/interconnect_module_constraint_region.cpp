// Source for AP210 application object
//     interconnect_module_constraint_region

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_constraint_region.h"

// Classes
#include <feature_shape_occurrence.h>
#include <ee_requirement_occurrence.h>

interconnect_module_constraint_region::interconnect_module_constraint_region() {
   initialize();
   }
interconnect_module_constraint_region::~interconnect_module_constraint_region() {
   // Free string attributes
   if (_design_specific_purpose != NULL) {
      free(_design_specific_purpose);
     }
   }
// intialize data members
void interconnect_module_constraint_region::initialize() {
   // Required attributes
   _area = NULL;
   _design_specific_purpose = NULL;
   _requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int interconnect_module_constraint_region::DynamicType(int ID) {
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
interconnect_module_constraint_region *interconnect_module_constraint_region::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_constraint_region *>(s);
      }
   return NULL;
   }
interconnect_module_constraint_region *interconnect_module_constraint_region::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_constraint_region *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_constraint_region *interconnect_module_constraint_region::Construct() {
   interconnect_module_constraint_region *result = NULL;

   // create the interconnect_module_constraint_region.
   result = new interconnect_module_constraint_region();
   return result;
   }
bool interconnect_module_constraint_region::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_constraint_region\r\n");

   // Check for the existence of all required attributes
   if (_keepout == NULL) {
      TRACE("ERROR: _keepout a required attribute is NULL!\r\n");
      result = false;
      }
   if (_area == NULL) {
      TRACE("ERROR: _area a required attribute is NULL!\r\n");
      result = false;
      }
   if (_scope == NULL) {
      TRACE("ERROR: _scope a required attribute is NULL!\r\n");
      result = false;
      }
   if (_design_specific_purpose == NULL) {
      TRACE("ERROR: _design_specific_purpose a required attribute is NULL!\r\n");
      result = false;
      }
   if (_requirement == NULL) {
      TRACE("ERROR: _requirement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_associated_stratum_extent == NULL) {
      TRACE("ERROR: _associated_stratum_extent a required attribute is NULL!\r\n");
      result = false;
      }
   if (_constrained_design_object_category == NULL) {
      TRACE("ERROR: _constrained_design_object_category a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
