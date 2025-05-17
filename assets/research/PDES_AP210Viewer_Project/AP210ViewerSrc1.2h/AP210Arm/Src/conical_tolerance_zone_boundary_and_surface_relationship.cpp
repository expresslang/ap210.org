// Source for AP210 application object
//     conical_tolerance_zone_boundary_and_surface_relationship

// Precompiled include files
#include <StdAfx.h>

#include "conical_tolerance_zone_boundary_and_surface_relationship.h"

// Classes
#include <conical_tolerance_zone_boundary.h>
#include <physical_feature_or_part_template.h>

conical_tolerance_zone_boundary_and_surface_relationship::conical_tolerance_zone_boundary_and_surface_relationship() {
   initialize();
   }
conical_tolerance_zone_boundary_and_surface_relationship::~conical_tolerance_zone_boundary_and_surface_relationship() {
   // Free string attributes
   }
// intialize data members
void conical_tolerance_zone_boundary_and_surface_relationship::initialize() {
   // Required attributes
   _sized_tolerance_zone_boundary = NULL;
   _terminating_surface = NULL;

   // Optional attributes
   }
// Runtime type identification
int conical_tolerance_zone_boundary_and_surface_relationship::DynamicType(int ID) {
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
conical_tolerance_zone_boundary_and_surface_relationship *conical_tolerance_zone_boundary_and_surface_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conical_tolerance_zone_boundary_and_surface_relationship *>(s);
      }
   return NULL;
   }
conical_tolerance_zone_boundary_and_surface_relationship *conical_tolerance_zone_boundary_and_surface_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conical_tolerance_zone_boundary_and_surface_relationship *>(s);
      }
   return NULL;
   }
// construction factory
conical_tolerance_zone_boundary_and_surface_relationship *conical_tolerance_zone_boundary_and_surface_relationship::Construct() {
   conical_tolerance_zone_boundary_and_surface_relationship *result = NULL;

   // create the conical_tolerance_zone_boundary_and_surface_relationship.
   result = new conical_tolerance_zone_boundary_and_surface_relationship();
   return result;
   }
bool conical_tolerance_zone_boundary_and_surface_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conical_tolerance_zone_boundary_and_surface_relationship\r\n");

   // Check for the existence of all required attributes
   if (_sized_tolerance_zone_boundary == NULL) {
      TRACE("ERROR: _sized_tolerance_zone_boundary a required attribute is NULL!\r\n");
      result = false;
      }
   if (_terminating_surface == NULL) {
      TRACE("ERROR: _terminating_surface a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
