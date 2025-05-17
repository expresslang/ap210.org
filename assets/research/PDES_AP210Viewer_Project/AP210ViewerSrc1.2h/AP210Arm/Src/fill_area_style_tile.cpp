// Source for AP210 application object
//     fill_area_style_tile

// Precompiled include files
#include <StdAfx.h>

#include "fill_area_style_tile.h"

// Classes
#include <positive_ratio_measure.h>

fill_area_style_tile::fill_area_style_tile() {
   initialize();
   }
fill_area_style_tile::~fill_area_style_tile() {
   // Free string attributes
   }
// intialize data members
void fill_area_style_tile::initialize() {
   // Required attributes
   _tiling_scale = NULL;

   // Optional attributes
   }
// Runtime type identification
int fill_area_style_tile::DynamicType(int ID) {
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
fill_area_style_tile *fill_area_style_tile::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fill_area_style_tile *>(s);
      }
   return NULL;
   }
fill_area_style_tile *fill_area_style_tile::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fill_area_style_tile *>(s);
      }
   return NULL;
   }
// construction factory
fill_area_style_tile *fill_area_style_tile::Construct() {
   fill_area_style_tile *result = NULL;

   // create the fill_area_style_tile.
   result = new fill_area_style_tile();
   return result;
   }
bool fill_area_style_tile::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fill_area_style_tile\r\n");

   // Check for the existence of all required attributes
   if (_tiling_pattern == NULL) {
      TRACE("ERROR: _tiling_pattern a required attribute is NULL!\r\n");
      result = false;
      }
   if (_tile == NULL) {
      TRACE("ERROR: _tile a required attribute is NULL!\r\n");
      result = false;
      }
   if (_tiling_scale == NULL) {
      TRACE("ERROR: _tiling_scale a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
