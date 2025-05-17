// Source for AP210 application object
//     seating_plane

// Precompiled include files
#include <StdAfx.h>

#include "seating_plane.h"

// Classes

seating_plane::seating_plane() {
   initialize();
   }
seating_plane::~seating_plane() {
   // Free string attributes
   }
// intialize data members
void seating_plane::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int seating_plane::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = non_feature_shape_element::DynamicType(ID);
      }
   return result;
   }
seating_plane *seating_plane::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<seating_plane *>(s);
      }
   return NULL;
   }
seating_plane *seating_plane::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<seating_plane *>(s);
      }
   return NULL;
   }
// construction factory
seating_plane *seating_plane::Construct() {
   seating_plane *result = NULL;

   // create the seating_plane.
   result = new seating_plane();
   return result;
   }
bool seating_plane::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: seating_plane\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (non_feature_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
