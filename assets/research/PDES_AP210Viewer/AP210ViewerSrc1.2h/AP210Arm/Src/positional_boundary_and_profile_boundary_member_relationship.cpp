// Source for AP210 application object
//     positional_boundary_and_profile_boundary_member_relationship

// Precompiled include files
#include <StdAfx.h>

#include "positional_boundary_and_profile_boundary_member_relationship.h"

// Classes
#include <profile_related_positional_boundary.h>
#include <tolerance_zone_boundary_member.h>

positional_boundary_and_profile_boundary_member_relationship::positional_boundary_and_profile_boundary_member_relationship() {
   initialize();
   }
positional_boundary_and_profile_boundary_member_relationship::~positional_boundary_and_profile_boundary_member_relationship() {
   // Free string attributes
   }
// intialize data members
void positional_boundary_and_profile_boundary_member_relationship::initialize() {
   // Required attributes
   _offset_positional_boundary = NULL;
   _base_profile_tolerance_zone_boundary_member = NULL;

   // Optional attributes
   }
// Runtime type identification
int positional_boundary_and_profile_boundary_member_relationship::DynamicType(int ID) {
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
positional_boundary_and_profile_boundary_member_relationship *positional_boundary_and_profile_boundary_member_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<positional_boundary_and_profile_boundary_member_relationship *>(s);
      }
   return NULL;
   }
positional_boundary_and_profile_boundary_member_relationship *positional_boundary_and_profile_boundary_member_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<positional_boundary_and_profile_boundary_member_relationship *>(s);
      }
   return NULL;
   }
// construction factory
positional_boundary_and_profile_boundary_member_relationship *positional_boundary_and_profile_boundary_member_relationship::Construct() {
   positional_boundary_and_profile_boundary_member_relationship *result = NULL;

   // create the positional_boundary_and_profile_boundary_member_relationship.
   result = new positional_boundary_and_profile_boundary_member_relationship();
   return result;
   }
bool positional_boundary_and_profile_boundary_member_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: positional_boundary_and_profile_boundary_member_relationship\r\n");

   // Check for the existence of all required attributes
   if (_offset_positional_boundary == NULL) {
      TRACE("ERROR: _offset_positional_boundary a required attribute is NULL!\r\n");
      result = false;
      }
   if (_base_profile_tolerance_zone_boundary_member == NULL) {
      TRACE("ERROR: _base_profile_tolerance_zone_boundary_member a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
