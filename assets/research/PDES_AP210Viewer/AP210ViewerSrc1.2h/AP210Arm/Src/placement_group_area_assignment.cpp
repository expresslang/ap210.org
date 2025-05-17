// Source for AP210 application object
//     placement_group_area_assignment

// Precompiled include files
#include <StdAfx.h>

#include "placement_group_area_assignment.h"

// Classes
#include <placement_group.h>
#include <mounting_restriction_area.h>

placement_group_area_assignment::placement_group_area_assignment() {
   initialize();
   }
placement_group_area_assignment::~placement_group_area_assignment() {
   // Free string attributes
   }
// intialize data members
void placement_group_area_assignment::initialize() {
   // Required attributes
   _placed_group = NULL;
   _area = NULL;

   // Optional attributes
   }
// Runtime type identification
int placement_group_area_assignment::DynamicType(int ID) {
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
placement_group_area_assignment *placement_group_area_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<placement_group_area_assignment *>(s);
      }
   return NULL;
   }
placement_group_area_assignment *placement_group_area_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<placement_group_area_assignment *>(s);
      }
   return NULL;
   }
// construction factory
placement_group_area_assignment *placement_group_area_assignment::Construct() {
   placement_group_area_assignment *result = NULL;

   // create the placement_group_area_assignment.
   result = new placement_group_area_assignment();
   return result;
   }
bool placement_group_area_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: placement_group_area_assignment\r\n");

   // Check for the existence of all required attributes
   if (_placed_group == NULL) {
      TRACE("ERROR: _placed_group a required attribute is NULL!\r\n");
      result = false;
      }
   if (_area == NULL) {
      TRACE("ERROR: _area a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
