// Source for AP210 application object
//     fill_area_style

// Precompiled include files
#include <StdAfx.h>

#include "fill_area_style.h"

// Classes

fill_area_style::fill_area_style() {
   initialize();
   }
fill_area_style::~fill_area_style() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void fill_area_style::initialize() {
   // Required attributes
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int fill_area_style::DynamicType(int ID) {
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
fill_area_style *fill_area_style::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fill_area_style *>(s);
      }
   return NULL;
   }
fill_area_style *fill_area_style::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fill_area_style *>(s);
      }
   return NULL;
   }
// construction factory
fill_area_style *fill_area_style::Construct() {
   fill_area_style *result = NULL;

   // create the fill_area_style.
   result = new fill_area_style();
   return result;
   }
bool fill_area_style::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fill_area_style\r\n");

   // Check for the existence of all required attributes
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_fill_style == NULL) {
      TRACE("ERROR: _fill_style a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
