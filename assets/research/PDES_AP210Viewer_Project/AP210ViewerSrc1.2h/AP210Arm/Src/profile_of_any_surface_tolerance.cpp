// Source for AP210 application object
//     profile_of_any_surface_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "profile_of_any_surface_tolerance.h"

// Classes

profile_of_any_surface_tolerance::profile_of_any_surface_tolerance() {
   initialize();
   }
profile_of_any_surface_tolerance::~profile_of_any_surface_tolerance() {
   // Free string attributes
   }
// intialize data members
void profile_of_any_surface_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int profile_of_any_surface_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = geometric_tolerance::DynamicType(ID);
      }
   return result;
   }
profile_of_any_surface_tolerance *profile_of_any_surface_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<profile_of_any_surface_tolerance *>(s);
      }
   return NULL;
   }
profile_of_any_surface_tolerance *profile_of_any_surface_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<profile_of_any_surface_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
profile_of_any_surface_tolerance *profile_of_any_surface_tolerance::Construct() {
   profile_of_any_surface_tolerance *result = NULL;

   // create the profile_of_any_surface_tolerance.
   result = new profile_of_any_surface_tolerance();
   return result;
   }
bool profile_of_any_surface_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: profile_of_any_surface_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
