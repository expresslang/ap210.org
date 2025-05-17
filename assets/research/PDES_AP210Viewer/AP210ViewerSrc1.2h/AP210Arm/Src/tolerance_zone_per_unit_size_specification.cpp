// Source for AP210 application object
//     tolerance_zone_per_unit_size_specification

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_zone_per_unit_size_specification.h"

// Classes
#include <tolerance_zone.h>

tolerance_zone_per_unit_size_specification::tolerance_zone_per_unit_size_specification() {
   initialize();
   }
tolerance_zone_per_unit_size_specification::~tolerance_zone_per_unit_size_specification() {
   // Free string attributes
   }
// intialize data members
void tolerance_zone_per_unit_size_specification::initialize() {
   // Required attributes
   _specified_tolerance_zone = NULL;

   // Optional attributes
   }
// Runtime type identification
int tolerance_zone_per_unit_size_specification::DynamicType(int ID) {
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
tolerance_zone_per_unit_size_specification *tolerance_zone_per_unit_size_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_zone_per_unit_size_specification *>(s);
      }
   return NULL;
   }
tolerance_zone_per_unit_size_specification *tolerance_zone_per_unit_size_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_zone_per_unit_size_specification *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_zone_per_unit_size_specification *tolerance_zone_per_unit_size_specification::Construct() {
   tolerance_zone_per_unit_size_specification *result = NULL;

   // create the tolerance_zone_per_unit_size_specification.
   result = new tolerance_zone_per_unit_size_specification();
   return result;
   }
bool tolerance_zone_per_unit_size_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_zone_per_unit_size_specification\r\n");

   // Check for the existence of all required attributes
   if (_specified_tolerance_zone == NULL) {
      TRACE("ERROR: _specified_tolerance_zone a required attribute is NULL!\r\n");
      result = false;
      }
   if (_per_unit_size == NULL) {
      TRACE("ERROR: _per_unit_size a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
