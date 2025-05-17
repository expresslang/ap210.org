// Source for AP210 application object
//     fill_area_style_tile_symbol_with_style

// Precompiled include files
#include <StdAfx.h>

#include "fill_area_style_tile_symbol_with_style.h"

// Classes

fill_area_style_tile_symbol_with_style::fill_area_style_tile_symbol_with_style() {
   initialize();
   }
fill_area_style_tile_symbol_with_style::~fill_area_style_tile_symbol_with_style() {
   // Free string attributes
   }
// intialize data members
void fill_area_style_tile_symbol_with_style::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int fill_area_style_tile_symbol_with_style::DynamicType(int ID) {
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
fill_area_style_tile_symbol_with_style *fill_area_style_tile_symbol_with_style::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fill_area_style_tile_symbol_with_style *>(s);
      }
   return NULL;
   }
fill_area_style_tile_symbol_with_style *fill_area_style_tile_symbol_with_style::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fill_area_style_tile_symbol_with_style *>(s);
      }
   return NULL;
   }
// construction factory
fill_area_style_tile_symbol_with_style *fill_area_style_tile_symbol_with_style::Construct() {
   fill_area_style_tile_symbol_with_style *result = NULL;

   // create the fill_area_style_tile_symbol_with_style.
   result = new fill_area_style_tile_symbol_with_style();
   return result;
   }
bool fill_area_style_tile_symbol_with_style::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fill_area_style_tile_symbol_with_style\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
