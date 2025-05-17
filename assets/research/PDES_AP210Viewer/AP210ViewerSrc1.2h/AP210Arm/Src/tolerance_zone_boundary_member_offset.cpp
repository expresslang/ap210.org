// Source for AP210 application object
//     tolerance_zone_boundary_member_offset

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_zone_boundary_member_offset.h"

// Classes
#include <tolerance_zone_boundary_member.h>
#include <length_data_element.h>

tolerance_zone_boundary_member_offset::tolerance_zone_boundary_member_offset() {
   initialize();
   }
tolerance_zone_boundary_member_offset::~tolerance_zone_boundary_member_offset() {
   // Free string attributes
   }
// intialize data members
void tolerance_zone_boundary_member_offset::initialize() {
   // Required attributes
   _offset_tolerance_zone_boundary_member = NULL;
   _offset_value = NULL;

   // Optional attributes
   }
// Runtime type identification
int tolerance_zone_boundary_member_offset::DynamicType(int ID) {
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
tolerance_zone_boundary_member_offset *tolerance_zone_boundary_member_offset::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_zone_boundary_member_offset *>(s);
      }
   return NULL;
   }
tolerance_zone_boundary_member_offset *tolerance_zone_boundary_member_offset::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_zone_boundary_member_offset *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_zone_boundary_member_offset *tolerance_zone_boundary_member_offset::Construct() {
   tolerance_zone_boundary_member_offset *result = NULL;

   // create the tolerance_zone_boundary_member_offset.
   result = new tolerance_zone_boundary_member_offset();
   return result;
   }
bool tolerance_zone_boundary_member_offset::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_zone_boundary_member_offset\r\n");

   // Check for the existence of all required attributes
   if (_offset_tolerance_zone_boundary_member == NULL) {
      TRACE("ERROR: _offset_tolerance_zone_boundary_member a required attribute is NULL!\r\n");
      result = false;
      }
   if (_offset_value == NULL) {
      TRACE("ERROR: _offset_value a required attribute is NULL!\r\n");
      result = false;
      }
   if (_type_of_offset == NULL) {
      TRACE("ERROR: _type_of_offset a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
