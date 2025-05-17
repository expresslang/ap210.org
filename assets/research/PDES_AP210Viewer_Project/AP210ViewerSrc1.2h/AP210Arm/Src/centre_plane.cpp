// Source for AP210 application object
//     centre_plane

// Precompiled include files
#include <StdAfx.h>

#include "centre_plane.h"

// Classes

centre_plane::centre_plane() {
   initialize();
   }
centre_plane::~centre_plane() {
   // Free string attributes
   }
// intialize data members
void centre_plane::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int centre_plane::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = centre_of_symmetry::DynamicType(ID);
      }
   return result;
   }
centre_plane *centre_plane::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<centre_plane *>(s);
      }
   return NULL;
   }
centre_plane *centre_plane::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<centre_plane *>(s);
      }
   return NULL;
   }
// construction factory
centre_plane *centre_plane::Construct() {
   centre_plane *result = NULL;

   // create the centre_plane.
   result = new centre_plane();
   return result;
   }
bool centre_plane::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: centre_plane\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (centre_of_symmetry::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
