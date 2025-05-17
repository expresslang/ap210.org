// Source for AP210 application object
//     projected_zone_height_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "projected_zone_height_characteristic.h"

// Classes
#include <projected_zone_and_base_relationship.h>
#include <length_data_element.h>

projected_zone_height_characteristic::projected_zone_height_characteristic() {
   initialize();
   }
projected_zone_height_characteristic::~projected_zone_height_characteristic() {
   // Free string attributes
   }
// intialize data members
void projected_zone_height_characteristic::initialize() {
   // Required attributes
   _defined_height_of = NULL;
   _projected_height_value = NULL;

   // Optional attributes
   }
// Runtime type identification
int projected_zone_height_characteristic::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
projected_zone_height_characteristic *projected_zone_height_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<projected_zone_height_characteristic *>(s);
      }
   return NULL;
   }
projected_zone_height_characteristic *projected_zone_height_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<projected_zone_height_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
projected_zone_height_characteristic *projected_zone_height_characteristic::Construct() {
   projected_zone_height_characteristic *result = NULL;

   // create the projected_zone_height_characteristic.
   result = new projected_zone_height_characteristic();
   return result;
   }
bool projected_zone_height_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: projected_zone_height_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_defined_height_of == NULL) {
      TRACE("ERROR: _defined_height_of a required attribute is NULL!\r\n");
      result = false;
      }
   if (_projected_height_value == NULL) {
      TRACE("ERROR: _projected_height_value a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
