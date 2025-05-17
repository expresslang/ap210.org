// Source for AP210 application object
//     layout_spacing_requirement_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "layout_spacing_requirement_occurrence.h"

// Classes

layout_spacing_requirement_occurrence::layout_spacing_requirement_occurrence() {
   initialize();
   }
layout_spacing_requirement_occurrence::~layout_spacing_requirement_occurrence() {
   // Free string attributes
   }
// intialize data members
void layout_spacing_requirement_occurrence::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int layout_spacing_requirement_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_requirement_occurrence::DynamicType(ID);
      }
   return result;
   }
layout_spacing_requirement_occurrence *layout_spacing_requirement_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<layout_spacing_requirement_occurrence *>(s);
      }
   return NULL;
   }
layout_spacing_requirement_occurrence *layout_spacing_requirement_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<layout_spacing_requirement_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
layout_spacing_requirement_occurrence *layout_spacing_requirement_occurrence::Construct() {
   layout_spacing_requirement_occurrence *result = NULL;

   // create the layout_spacing_requirement_occurrence.
   result = new layout_spacing_requirement_occurrence();
   return result;
   }
bool layout_spacing_requirement_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: layout_spacing_requirement_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_reference_design_object_category == NULL) {
      TRACE("ERROR: _reference_design_object_category a required attribute is NULL!\r\n");
      result = false;
      }
   if (_dependent_design_object_category == NULL) {
      TRACE("ERROR: _dependent_design_object_category a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (ee_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
