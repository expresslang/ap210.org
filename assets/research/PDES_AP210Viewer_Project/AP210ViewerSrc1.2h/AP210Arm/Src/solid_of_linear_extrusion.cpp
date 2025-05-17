// Source for AP210 application object
//     solid_of_linear_extrusion

// Precompiled include files
#include <StdAfx.h>

#include "solid_of_linear_extrusion.h"

// Classes

solid_of_linear_extrusion::solid_of_linear_extrusion() {
   initialize();
   }
solid_of_linear_extrusion::~solid_of_linear_extrusion() {
   // Free string attributes
   }
// intialize data members
void solid_of_linear_extrusion::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int solid_of_linear_extrusion::DynamicType(int ID) {
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
solid_of_linear_extrusion *solid_of_linear_extrusion::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<solid_of_linear_extrusion *>(s);
      }
   return NULL;
   }
solid_of_linear_extrusion *solid_of_linear_extrusion::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<solid_of_linear_extrusion *>(s);
      }
   return NULL;
   }
// construction factory
solid_of_linear_extrusion *solid_of_linear_extrusion::Construct() {
   solid_of_linear_extrusion *result = NULL;

   // create the solid_of_linear_extrusion.
   result = new solid_of_linear_extrusion();
   return result;
   }
bool solid_of_linear_extrusion::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: solid_of_linear_extrusion\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (bound_volume_shape::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
