// Source for AP210 application object
//     viewing_plane

// Precompiled include files
#include <StdAfx.h>

#include "viewing_plane.h"

// Classes

viewing_plane::viewing_plane() {
   initialize();
   }
viewing_plane::~viewing_plane() {
   // Free string attributes
   }
// intialize data members
void viewing_plane::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int viewing_plane::DynamicType(int ID) {
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
viewing_plane *viewing_plane::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<viewing_plane *>(s);
      }
   return NULL;
   }
viewing_plane *viewing_plane::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<viewing_plane *>(s);
      }
   return NULL;
   }
// construction factory
viewing_plane *viewing_plane::Construct() {
   viewing_plane *result = NULL;

   // create the viewing_plane.
   result = new viewing_plane();
   return result;
   }
bool viewing_plane::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: viewing_plane\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (non_feature_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
