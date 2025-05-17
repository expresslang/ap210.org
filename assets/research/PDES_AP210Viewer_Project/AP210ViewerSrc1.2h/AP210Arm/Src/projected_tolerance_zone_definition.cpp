// Source for AP210 application object
//     projected_tolerance_zone_definition

// Precompiled include files
#include <StdAfx.h>

#include "projected_tolerance_zone_definition.h"

// Classes
#include <projected_zone_height_characteristic.h>

projected_tolerance_zone_definition::projected_tolerance_zone_definition() {
   initialize();
   }
projected_tolerance_zone_definition::~projected_tolerance_zone_definition() {
   // Free string attributes
   }
// intialize data members
void projected_tolerance_zone_definition::initialize() {
   // Required attributes
   _projected_zone_height = NULL;

   // Optional attributes
   }
// Runtime type identification
int projected_tolerance_zone_definition::DynamicType(int ID) {
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
projected_tolerance_zone_definition *projected_tolerance_zone_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<projected_tolerance_zone_definition *>(s);
      }
   return NULL;
   }
projected_tolerance_zone_definition *projected_tolerance_zone_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<projected_tolerance_zone_definition *>(s);
      }
   return NULL;
   }
// construction factory
projected_tolerance_zone_definition *projected_tolerance_zone_definition::Construct() {
   projected_tolerance_zone_definition *result = NULL;

   // create the projected_tolerance_zone_definition.
   result = new projected_tolerance_zone_definition();
   return result;
   }
bool projected_tolerance_zone_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: projected_tolerance_zone_definition\r\n");

   // Check for the existence of all required attributes
   if (_projected_zone_height == NULL) {
      TRACE("ERROR: _projected_zone_height a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (tolerance_zone_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
