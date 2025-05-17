// Source for AP210 application object
//     conical_tolerance_zone_definition

// Precompiled include files
#include <StdAfx.h>

#include "conical_tolerance_zone_definition.h"

// Classes

conical_tolerance_zone_definition::conical_tolerance_zone_definition() {
   initialize();
   }
conical_tolerance_zone_definition::~conical_tolerance_zone_definition() {
   // Free string attributes
   }
// intialize data members
void conical_tolerance_zone_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int conical_tolerance_zone_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = tolerance_zone_definition::DynamicType(ID);
      }
   return result;
   }
conical_tolerance_zone_definition *conical_tolerance_zone_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conical_tolerance_zone_definition *>(s);
      }
   return NULL;
   }
conical_tolerance_zone_definition *conical_tolerance_zone_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conical_tolerance_zone_definition *>(s);
      }
   return NULL;
   }
// construction factory
conical_tolerance_zone_definition *conical_tolerance_zone_definition::Construct() {
   conical_tolerance_zone_definition *result = NULL;

   // create the conical_tolerance_zone_definition.
   result = new conical_tolerance_zone_definition();
   return result;
   }
bool conical_tolerance_zone_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conical_tolerance_zone_definition\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (tolerance_zone_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
