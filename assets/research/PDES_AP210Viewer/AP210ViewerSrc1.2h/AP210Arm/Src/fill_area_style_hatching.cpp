// Source for AP210 application object
//     fill_area_style_hatching

// Precompiled include files
#include <StdAfx.h>

#include "fill_area_style_hatching.h"

// Classes
#include <curve_style.h>
#include <vector.h>
#include <cartesian_point.h>
#include <cartesian_point.h>
#include <angle_data_element.h>

fill_area_style_hatching::fill_area_style_hatching() {
   initialize();
   }
fill_area_style_hatching::~fill_area_style_hatching() {
   // Free string attributes
   }
// intialize data members
void fill_area_style_hatching::initialize() {
   // Required attributes
   _hatch_line_appearance = NULL;
   _start_of_next_hatch_line = NULL;
   _point_of_reference_hatch_line = NULL;
   _pattern_start = NULL;
   _hatch_line_angle = NULL;

   // Optional attributes
   }
// Runtime type identification
int fill_area_style_hatching::DynamicType(int ID) {
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
fill_area_style_hatching *fill_area_style_hatching::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fill_area_style_hatching *>(s);
      }
   return NULL;
   }
fill_area_style_hatching *fill_area_style_hatching::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fill_area_style_hatching *>(s);
      }
   return NULL;
   }
// construction factory
fill_area_style_hatching *fill_area_style_hatching::Construct() {
   fill_area_style_hatching *result = NULL;

   // create the fill_area_style_hatching.
   result = new fill_area_style_hatching();
   return result;
   }
bool fill_area_style_hatching::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fill_area_style_hatching\r\n");

   // Check for the existence of all required attributes
   if (_hatch_line_appearance == NULL) {
      TRACE("ERROR: _hatch_line_appearance a required attribute is NULL!\r\n");
      result = false;
      }
   if (_start_of_next_hatch_line == NULL) {
      TRACE("ERROR: _start_of_next_hatch_line a required attribute is NULL!\r\n");
      result = false;
      }
   if (_point_of_reference_hatch_line == NULL) {
      TRACE("ERROR: _point_of_reference_hatch_line a required attribute is NULL!\r\n");
      result = false;
      }
   if (_pattern_start == NULL) {
      TRACE("ERROR: _pattern_start a required attribute is NULL!\r\n");
      result = false;
      }
   if (_hatch_line_angle == NULL) {
      TRACE("ERROR: _hatch_line_angle a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
