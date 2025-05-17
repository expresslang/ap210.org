// Source for AP210 application object
//     part_template_non_planar_2d_shape

// Precompiled include files
#include <StdAfx.h>

#include "part_template_non_planar_2d_shape.h"

// Classes
#include <axis_placement_3d.h>
#include <part_template.h>
#include <open_shell_based_surface.h>

part_template_non_planar_2d_shape::part_template_non_planar_2d_shape() {
   initialize();
   }
part_template_non_planar_2d_shape::~part_template_non_planar_2d_shape() {
   // Free string attributes
   }
// intialize data members
void part_template_non_planar_2d_shape::initialize() {
   // Required attributes
   _transformation = NULL;
   _shape_characterized_part_template = NULL;
   _shape_representation = NULL;

   // Optional attributes
   }
// Runtime type identification
int part_template_non_planar_2d_shape::DynamicType(int ID) {
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
part_template_non_planar_2d_shape *part_template_non_planar_2d_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_template_non_planar_2d_shape *>(s);
      }
   return NULL;
   }
part_template_non_planar_2d_shape *part_template_non_planar_2d_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_template_non_planar_2d_shape *>(s);
      }
   return NULL;
   }
// construction factory
part_template_non_planar_2d_shape *part_template_non_planar_2d_shape::Construct() {
   part_template_non_planar_2d_shape *result = NULL;

   // create the part_template_non_planar_2d_shape.
   result = new part_template_non_planar_2d_shape();
   return result;
   }
bool part_template_non_planar_2d_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_template_non_planar_2d_shape\r\n");

   // Check for the existence of all required attributes
   if (_transformation == NULL) {
      TRACE("ERROR: _transformation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_characterized_part_template == NULL) {
      TRACE("ERROR: _shape_characterized_part_template a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_representation == NULL) {
      TRACE("ERROR: _shape_representation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_material_condition == NULL) {
      TRACE("ERROR: _shape_material_condition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
