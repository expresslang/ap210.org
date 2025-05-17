// Source for AP210 application object
//     csg_solid

// Precompiled include files
#include <StdAfx.h>

#include "csg_solid.h"

// Classes

csg_solid::csg_solid() {
   initialize();
   }
csg_solid::~csg_solid() {
   // Free string attributes
   }
// intialize data members
void csg_solid::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int csg_solid::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = bound_volume_shape::DynamicType(ID);
      }
   return result;
   }
csg_solid *csg_solid::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<csg_solid *>(s);
      }
   return NULL;
   }
csg_solid *csg_solid::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<csg_solid *>(s);
      }
   return NULL;
   }
// construction factory
csg_solid *csg_solid::Construct() {
   csg_solid *result = NULL;

   // create the csg_solid.
   result = new csg_solid();
   return result;
   }
bool csg_solid::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: csg_solid\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (bound_volume_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
