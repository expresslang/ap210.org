// Source for AP210 application object
//     planar_projected_shape

// Precompiled include files
#include <StdAfx.h>

#include "planar_projected_shape.h"

// Classes

planar_projected_shape::planar_projected_shape() {
   initialize();
   }
planar_projected_shape::~planar_projected_shape() {
   // Free string attributes
   }
// intialize data members
void planar_projected_shape::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int planar_projected_shape::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = planar_shape::DynamicType(ID);
      }
   return result;
   }
planar_projected_shape *planar_projected_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<planar_projected_shape *>(s);
      }
   return NULL;
   }
planar_projected_shape *planar_projected_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<planar_projected_shape *>(s);
      }
   return NULL;
   }
// construction factory
planar_projected_shape *planar_projected_shape::Construct() {
   planar_projected_shape *result = NULL;

   // create the planar_projected_shape.
   result = new planar_projected_shape();
   return result;
   }
bool planar_projected_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: planar_projected_shape\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (planar_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
