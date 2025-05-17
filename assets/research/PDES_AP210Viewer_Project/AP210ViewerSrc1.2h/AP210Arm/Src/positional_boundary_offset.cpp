// Source for AP210 application object
//     positional_boundary_offset

// Precompiled include files
#include <StdAfx.h>

#include "positional_boundary_offset.h"

// Classes
#include <positional_boundary_and_profile_boundary_member_relationship.h>
#include <length_data_element.h>

positional_boundary_offset::positional_boundary_offset() {
   initialize();
   }
positional_boundary_offset::~positional_boundary_offset() {
   // Free string attributes
   }
// intialize data members
void positional_boundary_offset::initialize() {
   // Required attributes
   _offset_boundary_relationship = NULL;
   _tolerance_value = NULL;

   // Optional attributes
   }
// Runtime type identification
int positional_boundary_offset::DynamicType(int ID) {
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
positional_boundary_offset *positional_boundary_offset::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<positional_boundary_offset *>(s);
      }
   return NULL;
   }
positional_boundary_offset *positional_boundary_offset::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<positional_boundary_offset *>(s);
      }
   return NULL;
   }
// construction factory
positional_boundary_offset *positional_boundary_offset::Construct() {
   positional_boundary_offset *result = NULL;

   // create the positional_boundary_offset.
   result = new positional_boundary_offset();
   return result;
   }
bool positional_boundary_offset::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: positional_boundary_offset\r\n");

   // Check for the existence of all required attributes
   if (_offset_boundary_relationship == NULL) {
      TRACE("ERROR: _offset_boundary_relationship a required attribute is NULL!\r\n");
      result = false;
      }
   if (_tolerance_value == NULL) {
      TRACE("ERROR: _tolerance_value a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
