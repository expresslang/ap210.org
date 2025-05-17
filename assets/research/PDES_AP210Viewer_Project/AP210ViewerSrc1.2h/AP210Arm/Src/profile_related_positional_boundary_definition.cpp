// Source for AP210 application object
//     profile_related_positional_boundary_definition

// Precompiled include files
#include <StdAfx.h>

#include "profile_related_positional_boundary_definition.h"

// Classes
#include <positional_boundary_offset.h>

profile_related_positional_boundary_definition::profile_related_positional_boundary_definition() {
   initialize();
   }
profile_related_positional_boundary_definition::~profile_related_positional_boundary_definition() {
   // Free string attributes
   }
// intialize data members
void profile_related_positional_boundary_definition::initialize() {
   // Required attributes
   _boundary_offset = NULL;

   // Optional attributes
   }
// Runtime type identification
int profile_related_positional_boundary_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = positional_boundary_definition::DynamicType(ID);
      }
   return result;
   }
profile_related_positional_boundary_definition *profile_related_positional_boundary_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<profile_related_positional_boundary_definition *>(s);
      }
   return NULL;
   }
profile_related_positional_boundary_definition *profile_related_positional_boundary_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<profile_related_positional_boundary_definition *>(s);
      }
   return NULL;
   }
// construction factory
profile_related_positional_boundary_definition *profile_related_positional_boundary_definition::Construct() {
   profile_related_positional_boundary_definition *result = NULL;

   // create the profile_related_positional_boundary_definition.
   result = new profile_related_positional_boundary_definition();
   return result;
   }
bool profile_related_positional_boundary_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: profile_related_positional_boundary_definition\r\n");

   // Check for the existence of all required attributes
   if (_boundary_offset == NULL) {
      TRACE("ERROR: _boundary_offset a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (positional_boundary_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
