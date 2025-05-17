// Source for AP210 application object
//     layout_spacing_requirement_non_conforming_design_object

// Precompiled include files
#include <StdAfx.h>

#include "layout_spacing_requirement_non_conforming_design_object.h"

// Classes
#include <layout_spacing_requirement_occurrence.h>

layout_spacing_requirement_non_conforming_design_object::layout_spacing_requirement_non_conforming_design_object() {
   initialize();
   }
layout_spacing_requirement_non_conforming_design_object::~layout_spacing_requirement_non_conforming_design_object() {
   // Free string attributes
   }
// intialize data members
void layout_spacing_requirement_non_conforming_design_object::initialize() {
   // Required attributes
   _design_requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int layout_spacing_requirement_non_conforming_design_object::DynamicType(int ID) {
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
layout_spacing_requirement_non_conforming_design_object *layout_spacing_requirement_non_conforming_design_object::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<layout_spacing_requirement_non_conforming_design_object *>(s);
      }
   return NULL;
   }
layout_spacing_requirement_non_conforming_design_object *layout_spacing_requirement_non_conforming_design_object::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<layout_spacing_requirement_non_conforming_design_object *>(s);
      }
   return NULL;
   }
// construction factory
layout_spacing_requirement_non_conforming_design_object *layout_spacing_requirement_non_conforming_design_object::Construct() {
   layout_spacing_requirement_non_conforming_design_object *result = NULL;

   // create the layout_spacing_requirement_non_conforming_design_object.
   result = new layout_spacing_requirement_non_conforming_design_object();
   return result;
   }
bool layout_spacing_requirement_non_conforming_design_object::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: layout_spacing_requirement_non_conforming_design_object\r\n");

   // Check for the existence of all required attributes
   if (_non_conformant_design_object == NULL) {
      TRACE("ERROR: _non_conformant_design_object a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_design_object == NULL) {
      TRACE("ERROR: _reference_design_object a required attribute is NULL!\r\n");
      result = false;
      }
   if (_design_requirement == NULL) {
      TRACE("ERROR: _design_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
