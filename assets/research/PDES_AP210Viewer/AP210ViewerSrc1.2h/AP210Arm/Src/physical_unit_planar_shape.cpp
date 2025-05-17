// Source for AP210 application object
//     physical_unit_planar_shape

// Precompiled include files
#include <StdAfx.h>

#include "physical_unit_planar_shape.h"

// Classes
#include <ee_requirement_occurrence.h>
#include <planar_projected_shape.h>
#include <physical_unit.h>
#include <cartesian_point.h>

physical_unit_planar_shape::physical_unit_planar_shape() {
   initialize();
   }
physical_unit_planar_shape::~physical_unit_planar_shape() {
   // Free string attributes
   }
// intialize data members
void physical_unit_planar_shape::initialize() {
   // Required attributes
   _application_technology_constraint = NULL;
   _shape_representation = NULL;
   _shape_characterized_physical_unit = NULL;

   // Optional attributes
   _centroid_location = NULL;
   }
// Runtime type identification
int physical_unit_planar_shape::DynamicType(int ID) {
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
physical_unit_planar_shape *physical_unit_planar_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_unit_planar_shape *>(s);
      }
   return NULL;
   }
physical_unit_planar_shape *physical_unit_planar_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_unit_planar_shape *>(s);
      }
   return NULL;
   }
// construction factory
physical_unit_planar_shape *physical_unit_planar_shape::Construct() {
   physical_unit_planar_shape *result = NULL;

   // create the physical_unit_planar_shape.
   result = new physical_unit_planar_shape();
   return result;
   }
bool physical_unit_planar_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_unit_planar_shape\r\n");

   // Check for the existence of all required attributes
   if (_application_technology_constraint == NULL) {
      TRACE("ERROR: _application_technology_constraint a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_representation == NULL) {
      TRACE("ERROR: _shape_representation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_characterized_physical_unit == NULL) {
      TRACE("ERROR: _shape_characterized_physical_unit a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_material_condition == NULL) {
      TRACE("ERROR: _shape_material_condition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_environment == NULL) {
      TRACE("ERROR: _shape_environment a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_purpose == NULL) {
      TRACE("ERROR: _shape_purpose a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
