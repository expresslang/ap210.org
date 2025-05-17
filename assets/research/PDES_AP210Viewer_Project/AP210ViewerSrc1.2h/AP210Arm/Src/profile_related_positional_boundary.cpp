// Source for AP210 application object
//     profile_related_positional_boundary

// Precompiled include files
#include <StdAfx.h>

#include "profile_related_positional_boundary.h"

// Classes

profile_related_positional_boundary::profile_related_positional_boundary() {
   initialize();
   }
profile_related_positional_boundary::~profile_related_positional_boundary() {
   // Free string attributes
   }
// intialize data members
void profile_related_positional_boundary::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int profile_related_positional_boundary::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = positional_boundary::DynamicType(ID);
      }
   return result;
   }
profile_related_positional_boundary *profile_related_positional_boundary::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<profile_related_positional_boundary *>(s);
      }
   return NULL;
   }
profile_related_positional_boundary *profile_related_positional_boundary::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<profile_related_positional_boundary *>(s);
      }
   return NULL;
   }
// construction factory
profile_related_positional_boundary *profile_related_positional_boundary::Construct() {
   profile_related_positional_boundary *result = NULL;

   // create the profile_related_positional_boundary.
   result = new profile_related_positional_boundary();
   return result;
   }
bool profile_related_positional_boundary::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: profile_related_positional_boundary\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (positional_boundary::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
