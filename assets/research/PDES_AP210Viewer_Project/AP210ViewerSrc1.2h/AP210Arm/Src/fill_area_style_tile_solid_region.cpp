// Source for AP210 application object
//     fill_area_style_tile_solid_region

// Precompiled include files
#include <StdAfx.h>

#include "fill_area_style_tile_solid_region.h"

// Classes

fill_area_style_tile_solid_region::fill_area_style_tile_solid_region() {
   initialize();
   }
fill_area_style_tile_solid_region::~fill_area_style_tile_solid_region() {
   // Free string attributes
   }
// intialize data members
void fill_area_style_tile_solid_region::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int fill_area_style_tile_solid_region::DynamicType(int ID) {
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
fill_area_style_tile_solid_region *fill_area_style_tile_solid_region::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fill_area_style_tile_solid_region *>(s);
      }
   return NULL;
   }
fill_area_style_tile_solid_region *fill_area_style_tile_solid_region::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fill_area_style_tile_solid_region *>(s);
      }
   return NULL;
   }
// construction factory
fill_area_style_tile_solid_region *fill_area_style_tile_solid_region::Construct() {
   fill_area_style_tile_solid_region *result = NULL;

   // create the fill_area_style_tile_solid_region.
   result = new fill_area_style_tile_solid_region();
   return result;
   }
bool fill_area_style_tile_solid_region::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fill_area_style_tile_solid_region\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
