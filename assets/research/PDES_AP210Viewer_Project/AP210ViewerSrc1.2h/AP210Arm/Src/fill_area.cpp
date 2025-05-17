// Source for AP210 application object
//     fill_area

// Precompiled include files
#include <StdAfx.h>

#include "fill_area.h"

// Classes

fill_area::fill_area() {
   initialize();
   }
fill_area::~fill_area() {
   // Free string attributes
   }
// intialize data members
void fill_area::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int fill_area::DynamicType(int ID) {
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
fill_area *fill_area::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fill_area *>(s);
      }
   return NULL;
   }
fill_area *fill_area::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fill_area *>(s);
      }
   return NULL;
   }
// construction factory
fill_area *fill_area::Construct() {
   fill_area *result = NULL;

   // create the fill_area.
   result = new fill_area();
   return result;
   }
bool fill_area::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fill_area\r\n");

   // Check for the existence of all required attributes
   if (_boundary == NULL) {
      TRACE("ERROR: _boundary a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
