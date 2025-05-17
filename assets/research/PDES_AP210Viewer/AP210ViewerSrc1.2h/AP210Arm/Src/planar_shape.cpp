// Source for AP210 application object
//     planar_shape

// Precompiled include files
#include <StdAfx.h>

#include "planar_shape.h"

// Classes

planar_shape::planar_shape() {
   initialize();
   }
planar_shape::~planar_shape() {
   // Free string attributes
   }
// intialize data members
void planar_shape::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int planar_shape::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = feature_shape_definition::DynamicType(ID);
      }
   return result;
   }
planar_shape *planar_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<planar_shape *>(s);
      }
   return NULL;
   }
planar_shape *planar_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<planar_shape *>(s);
      }
   return NULL;
   }
// construction factory
planar_shape *planar_shape::Construct() {
   planar_shape *result = NULL;

   // create the planar_shape.
   result = new planar_shape();
   return result;
   }
bool planar_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: planar_shape\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (feature_shape_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
