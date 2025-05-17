// Source for AP210 application object
//     profile_boundary_definition

// Precompiled include files
#include <StdAfx.h>

#include "profile_boundary_definition.h"

// Classes
#include <true_profile.h>

profile_boundary_definition::profile_boundary_definition() {
   initialize();
   }
profile_boundary_definition::~profile_boundary_definition() {
   // Free string attributes
   }
// intialize data members
void profile_boundary_definition::initialize() {
   // Required attributes
   _basic_profile = NULL;

   // Optional attributes
   }
// Runtime type identification
int profile_boundary_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = boundary_zone_definition_with_specified_size::DynamicType(ID);
      }
   return result;
   }
profile_boundary_definition *profile_boundary_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<profile_boundary_definition *>(s);
      }
   return NULL;
   }
profile_boundary_definition *profile_boundary_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<profile_boundary_definition *>(s);
      }
   return NULL;
   }
// construction factory
profile_boundary_definition *profile_boundary_definition::Construct() {
   profile_boundary_definition *result = NULL;

   // create the profile_boundary_definition.
   result = new profile_boundary_definition();
   return result;
   }
bool profile_boundary_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: profile_boundary_definition\r\n");

   // Check for the existence of all required attributes
   if (_basic_profile == NULL) {
      TRACE("ERROR: _basic_profile a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (boundary_zone_definition_with_specified_size::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
