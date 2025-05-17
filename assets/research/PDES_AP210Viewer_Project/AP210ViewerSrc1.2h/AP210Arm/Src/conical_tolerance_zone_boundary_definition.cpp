// Source for AP210 application object
//     conical_tolerance_zone_boundary_definition

// Precompiled include files
#include <StdAfx.h>

#include "conical_tolerance_zone_boundary_definition.h"

// Classes

conical_tolerance_zone_boundary_definition::conical_tolerance_zone_boundary_definition() {
   initialize();
   }
conical_tolerance_zone_boundary_definition::~conical_tolerance_zone_boundary_definition() {
   // Free string attributes
   }
// intialize data members
void conical_tolerance_zone_boundary_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int conical_tolerance_zone_boundary_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = tolerance_zone_boundary_definition::DynamicType(ID);
      }
   return result;
   }
conical_tolerance_zone_boundary_definition *conical_tolerance_zone_boundary_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conical_tolerance_zone_boundary_definition *>(s);
      }
   return NULL;
   }
conical_tolerance_zone_boundary_definition *conical_tolerance_zone_boundary_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conical_tolerance_zone_boundary_definition *>(s);
      }
   return NULL;
   }
// construction factory
conical_tolerance_zone_boundary_definition *conical_tolerance_zone_boundary_definition::Construct() {
   conical_tolerance_zone_boundary_definition *result = NULL;

   // create the conical_tolerance_zone_boundary_definition.
   result = new conical_tolerance_zone_boundary_definition();
   return result;
   }
bool conical_tolerance_zone_boundary_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conical_tolerance_zone_boundary_definition\r\n");

   // Check for the existence of all required attributes
   if (_boundary_sizes == NULL) {
      TRACE("ERROR: _boundary_sizes a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (tolerance_zone_boundary_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
