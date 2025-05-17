// Source for AP210 application object
//     tolerance_zone_and_viewing_plane_orienting_relationship

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_zone_and_viewing_plane_orienting_relationship.h"

// Classes
#include <viewing_plane.h>
#include <tolerance_zone.h>

tolerance_zone_and_viewing_plane_orienting_relationship::tolerance_zone_and_viewing_plane_orienting_relationship() {
   initialize();
   }
tolerance_zone_and_viewing_plane_orienting_relationship::~tolerance_zone_and_viewing_plane_orienting_relationship() {
   // Free string attributes
   }
// intialize data members
void tolerance_zone_and_viewing_plane_orienting_relationship::initialize() {
   // Required attributes
   _orienting_viewing_plane = NULL;
   _oriented_tolerance_zone = NULL;

   // Optional attributes
   }
// Runtime type identification
int tolerance_zone_and_viewing_plane_orienting_relationship::DynamicType(int ID) {
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
tolerance_zone_and_viewing_plane_orienting_relationship *tolerance_zone_and_viewing_plane_orienting_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_zone_and_viewing_plane_orienting_relationship *>(s);
      }
   return NULL;
   }
tolerance_zone_and_viewing_plane_orienting_relationship *tolerance_zone_and_viewing_plane_orienting_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_zone_and_viewing_plane_orienting_relationship *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_zone_and_viewing_plane_orienting_relationship *tolerance_zone_and_viewing_plane_orienting_relationship::Construct() {
   tolerance_zone_and_viewing_plane_orienting_relationship *result = NULL;

   // create the tolerance_zone_and_viewing_plane_orienting_relationship.
   result = new tolerance_zone_and_viewing_plane_orienting_relationship();
   return result;
   }
bool tolerance_zone_and_viewing_plane_orienting_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_zone_and_viewing_plane_orienting_relationship\r\n");

   // Check for the existence of all required attributes
   if (_orienting_viewing_plane == NULL) {
      TRACE("ERROR: _orienting_viewing_plane a required attribute is NULL!\r\n");
      result = false;
      }
   if (_oriented_tolerance_zone == NULL) {
      TRACE("ERROR: _oriented_tolerance_zone a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
