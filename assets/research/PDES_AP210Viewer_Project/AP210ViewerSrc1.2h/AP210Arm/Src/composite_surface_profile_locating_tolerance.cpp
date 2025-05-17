// Source for AP210 application object
//     composite_surface_profile_locating_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "composite_surface_profile_locating_tolerance.h"

// Classes

composite_surface_profile_locating_tolerance::composite_surface_profile_locating_tolerance() {
   initialize();
   }
composite_surface_profile_locating_tolerance::~composite_surface_profile_locating_tolerance() {
   // Free string attributes
   }
// intialize data members
void composite_surface_profile_locating_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int composite_surface_profile_locating_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = profile_of_any_surface_tolerance_with_referenced_datum_system::DynamicType(ID);
      }
   return result;
   }
composite_surface_profile_locating_tolerance *composite_surface_profile_locating_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<composite_surface_profile_locating_tolerance *>(s);
      }
   return NULL;
   }
composite_surface_profile_locating_tolerance *composite_surface_profile_locating_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<composite_surface_profile_locating_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
composite_surface_profile_locating_tolerance *composite_surface_profile_locating_tolerance::Construct() {
   composite_surface_profile_locating_tolerance *result = NULL;

   // create the composite_surface_profile_locating_tolerance.
   result = new composite_surface_profile_locating_tolerance();
   return result;
   }
bool composite_surface_profile_locating_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: composite_surface_profile_locating_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (profile_of_any_surface_tolerance_with_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
