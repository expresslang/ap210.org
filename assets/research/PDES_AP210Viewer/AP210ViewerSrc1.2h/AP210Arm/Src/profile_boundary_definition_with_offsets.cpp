// Source for AP210 application object
//     profile_boundary_definition_with_offsets

// Precompiled include files
#include <StdAfx.h>

#include "profile_boundary_definition_with_offsets.h"

// Classes

profile_boundary_definition_with_offsets::profile_boundary_definition_with_offsets() {
   initialize();
   }
profile_boundary_definition_with_offsets::~profile_boundary_definition_with_offsets() {
   // Free string attributes
   }
// intialize data members
void profile_boundary_definition_with_offsets::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int profile_boundary_definition_with_offsets::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = profile_boundary_definition::DynamicType(ID);
      }
   return result;
   }
profile_boundary_definition_with_offsets *profile_boundary_definition_with_offsets::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<profile_boundary_definition_with_offsets *>(s);
      }
   return NULL;
   }
profile_boundary_definition_with_offsets *profile_boundary_definition_with_offsets::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<profile_boundary_definition_with_offsets *>(s);
      }
   return NULL;
   }
// construction factory
profile_boundary_definition_with_offsets *profile_boundary_definition_with_offsets::Construct() {
   profile_boundary_definition_with_offsets *result = NULL;

   // create the profile_boundary_definition_with_offsets.
   result = new profile_boundary_definition_with_offsets();
   return result;
   }
bool profile_boundary_definition_with_offsets::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: profile_boundary_definition_with_offsets\r\n");

   // Check for the existence of all required attributes
   if (_boundary_offsets == NULL) {
      TRACE("ERROR: _boundary_offsets a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (profile_boundary_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
