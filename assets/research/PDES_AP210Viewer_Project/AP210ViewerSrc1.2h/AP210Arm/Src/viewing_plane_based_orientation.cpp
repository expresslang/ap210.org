// Source for AP210 application object
//     viewing_plane_based_orientation

// Precompiled include files
#include <StdAfx.h>

#include "viewing_plane_based_orientation.h"

// Classes
#include <tolerance_zone_and_viewing_plane_orienting_relationship.h>
#include <viewing_plane_definition.h>

viewing_plane_based_orientation::viewing_plane_based_orientation() {
   initialize();
   }
viewing_plane_based_orientation::~viewing_plane_based_orientation() {
   // Free string attributes
   }
// intialize data members
void viewing_plane_based_orientation::initialize() {
   // Required attributes
   _orienting_relationship = NULL;
   _viewing_plane_specification = NULL;

   // Optional attributes
   }
// Runtime type identification
int viewing_plane_based_orientation::DynamicType(int ID) {
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
viewing_plane_based_orientation *viewing_plane_based_orientation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<viewing_plane_based_orientation *>(s);
      }
   return NULL;
   }
viewing_plane_based_orientation *viewing_plane_based_orientation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<viewing_plane_based_orientation *>(s);
      }
   return NULL;
   }
// construction factory
viewing_plane_based_orientation *viewing_plane_based_orientation::Construct() {
   viewing_plane_based_orientation *result = NULL;

   // create the viewing_plane_based_orientation.
   result = new viewing_plane_based_orientation();
   return result;
   }
bool viewing_plane_based_orientation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: viewing_plane_based_orientation\r\n");

   // Check for the existence of all required attributes
   if (_orienting_relationship == NULL) {
      TRACE("ERROR: _orienting_relationship a required attribute is NULL!\r\n");
      result = false;
      }
   if (_viewing_plane_specification == NULL) {
      TRACE("ERROR: _viewing_plane_specification a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
