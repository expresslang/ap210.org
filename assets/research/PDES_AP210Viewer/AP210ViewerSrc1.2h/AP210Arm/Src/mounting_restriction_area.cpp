// Source for AP210 application object
//     mounting_restriction_area

// Precompiled include files
#include <StdAfx.h>

#include "mounting_restriction_area.h"

// Classes
#include <feature_shape_occurrence.h>
#include <interconnect_module_component_surface_feature.h>
#include <interconnect_module_component.h>

mounting_restriction_area::mounting_restriction_area() {
   initialize();
   }
mounting_restriction_area::~mounting_restriction_area() {
   // Free string attributes
   }
// intialize data members
void mounting_restriction_area::initialize() {
   // Required attributes
   _area = NULL;
   _mounting_surface = NULL;
   _scope = NULL;

   // Optional attributes
   }
// Runtime type identification
int mounting_restriction_area::DynamicType(int ID) {
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
mounting_restriction_area *mounting_restriction_area::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<mounting_restriction_area *>(s);
      }
   return NULL;
   }
mounting_restriction_area *mounting_restriction_area::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<mounting_restriction_area *>(s);
      }
   return NULL;
   }
// construction factory
mounting_restriction_area *mounting_restriction_area::Construct() {
   mounting_restriction_area *result = NULL;

   // create the mounting_restriction_area.
   result = new mounting_restriction_area();
   return result;
   }
bool mounting_restriction_area::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: mounting_restriction_area\r\n");

   // Check for the existence of all required attributes
   if (_area == NULL) {
      TRACE("ERROR: _area a required attribute is NULL!\r\n");
      result = false;
      }
   if (_mounting_surface == NULL) {
      TRACE("ERROR: _mounting_surface a required attribute is NULL!\r\n");
      result = false;
      }
   if (_scope == NULL) {
      TRACE("ERROR: _scope a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
