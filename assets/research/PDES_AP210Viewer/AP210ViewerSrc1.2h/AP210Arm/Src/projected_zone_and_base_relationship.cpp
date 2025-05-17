// Source for AP210 application object
//     projected_zone_and_base_relationship

// Precompiled include files
#include <StdAfx.h>

#include "projected_zone_and_base_relationship.h"

// Classes
#include <physical_feature_or_part_template.h>
#include <tolerance_zone.h>

projected_zone_and_base_relationship::projected_zone_and_base_relationship() {
   initialize();
   }
projected_zone_and_base_relationship::~projected_zone_and_base_relationship() {
   // Free string attributes
   }
// intialize data members
void projected_zone_and_base_relationship::initialize() {
   // Required attributes
   _base_physical_feature = NULL;
   _projected_zone = NULL;

   // Optional attributes
   }
// Runtime type identification
int projected_zone_and_base_relationship::DynamicType(int ID) {
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
projected_zone_and_base_relationship *projected_zone_and_base_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<projected_zone_and_base_relationship *>(s);
      }
   return NULL;
   }
projected_zone_and_base_relationship *projected_zone_and_base_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<projected_zone_and_base_relationship *>(s);
      }
   return NULL;
   }
// construction factory
projected_zone_and_base_relationship *projected_zone_and_base_relationship::Construct() {
   projected_zone_and_base_relationship *result = NULL;

   // create the projected_zone_and_base_relationship.
   result = new projected_zone_and_base_relationship();
   return result;
   }
bool projected_zone_and_base_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: projected_zone_and_base_relationship\r\n");

   // Check for the existence of all required attributes
   if (_base_physical_feature == NULL) {
      TRACE("ERROR: _base_physical_feature a required attribute is NULL!\r\n");
      result = false;
      }
   if (_projected_zone == NULL) {
      TRACE("ERROR: _projected_zone a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
