// Source for AP210 application object
//     conical_tolerance_zone_boundary

// Precompiled include files
#include <StdAfx.h>

#include "conical_tolerance_zone_boundary.h"

// Classes

conical_tolerance_zone_boundary::conical_tolerance_zone_boundary() {
   initialize();
   }
conical_tolerance_zone_boundary::~conical_tolerance_zone_boundary() {
   // Free string attributes
   }
// intialize data members
void conical_tolerance_zone_boundary::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int conical_tolerance_zone_boundary::DynamicType(int ID) {
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
conical_tolerance_zone_boundary *conical_tolerance_zone_boundary::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conical_tolerance_zone_boundary *>(s);
      }
   return NULL;
   }
conical_tolerance_zone_boundary *conical_tolerance_zone_boundary::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conical_tolerance_zone_boundary *>(s);
      }
   return NULL;
   }
// construction factory
conical_tolerance_zone_boundary *conical_tolerance_zone_boundary::Construct() {
   conical_tolerance_zone_boundary *result = NULL;

   // create the conical_tolerance_zone_boundary.
   result = new conical_tolerance_zone_boundary();
   return result;
   }
bool conical_tolerance_zone_boundary::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conical_tolerance_zone_boundary\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (tolerance_zone_boundary::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
