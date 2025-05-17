// Source for AP210 application object
//     fill_area_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "fill_area_occurrence.h"

// Classes
#include <fill_area.h>
#include <cartesian_point.h>
#include <curve_style.h>

fill_area_occurrence::fill_area_occurrence() {
   initialize();
   }
fill_area_occurrence::~fill_area_occurrence() {
   // Free string attributes
   }
// intialize data members
void fill_area_occurrence::initialize() {
   // Required attributes
   _filled_area = NULL;
   _fill_style_target = NULL;
   _boundary_style = NULL;

   // Optional attributes
   }
// Runtime type identification
int fill_area_occurrence::DynamicType(int ID) {
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
fill_area_occurrence *fill_area_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fill_area_occurrence *>(s);
      }
   return NULL;
   }
fill_area_occurrence *fill_area_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fill_area_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
fill_area_occurrence *fill_area_occurrence::Construct() {
   fill_area_occurrence *result = NULL;

   // create the fill_area_occurrence.
   result = new fill_area_occurrence();
   return result;
   }
bool fill_area_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fill_area_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_style == NULL) {
      TRACE("ERROR: _style a required attribute is NULL!\r\n");
      result = false;
      }
   if (_filled_area == NULL) {
      TRACE("ERROR: _filled_area a required attribute is NULL!\r\n");
      result = false;
      }
   if (_fill_style_target == NULL) {
      TRACE("ERROR: _fill_style_target a required attribute is NULL!\r\n");
      result = false;
      }
   if (_boundary_style == NULL) {
      TRACE("ERROR: _boundary_style a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
