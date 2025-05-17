// Source for AP210 application object
//     tolerance_zone_circular_or_cylindrical_or_spherical_boundary

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_zone_circular_or_cylindrical_or_spherical_boundary.h"

// Classes

tolerance_zone_circular_or_cylindrical_or_spherical_boundary::tolerance_zone_circular_or_cylindrical_or_spherical_boundary() {
   initialize();
   }
tolerance_zone_circular_or_cylindrical_or_spherical_boundary::~tolerance_zone_circular_or_cylindrical_or_spherical_boundary() {
   // Free string attributes
   }
// intialize data members
void tolerance_zone_circular_or_cylindrical_or_spherical_boundary::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int tolerance_zone_circular_or_cylindrical_or_spherical_boundary::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = tolerance_zone_boundary::DynamicType(ID);
      }
   return result;
   }
tolerance_zone_circular_or_cylindrical_or_spherical_boundary *tolerance_zone_circular_or_cylindrical_or_spherical_boundary::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_zone_circular_or_cylindrical_or_spherical_boundary *>(s);
      }
   return NULL;
   }
tolerance_zone_circular_or_cylindrical_or_spherical_boundary *tolerance_zone_circular_or_cylindrical_or_spherical_boundary::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_zone_circular_or_cylindrical_or_spherical_boundary *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_zone_circular_or_cylindrical_or_spherical_boundary *tolerance_zone_circular_or_cylindrical_or_spherical_boundary::Construct() {
   tolerance_zone_circular_or_cylindrical_or_spherical_boundary *result = NULL;

   // create the tolerance_zone_circular_or_cylindrical_or_spherical_boundary.
   result = new tolerance_zone_circular_or_cylindrical_or_spherical_boundary();
   return result;
   }
bool tolerance_zone_circular_or_cylindrical_or_spherical_boundary::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_zone_circular_or_cylindrical_or_spherical_boundary\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (tolerance_zone_boundary::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
