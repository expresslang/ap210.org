// Source for AP210 application object
//     tolerance_zone_definition_with_per_unit_size_specification

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_zone_definition_with_per_unit_size_specification.h"

// Classes
#include <tolerance_zone_per_unit_size_specification.h>

tolerance_zone_definition_with_per_unit_size_specification::tolerance_zone_definition_with_per_unit_size_specification() {
   initialize();
   }
tolerance_zone_definition_with_per_unit_size_specification::~tolerance_zone_definition_with_per_unit_size_specification() {
   // Free string attributes
   }
// intialize data members
void tolerance_zone_definition_with_per_unit_size_specification::initialize() {
   // Required attributes
   _per_unit_size_specification = NULL;

   // Optional attributes
   }
// Runtime type identification
int tolerance_zone_definition_with_per_unit_size_specification::DynamicType(int ID) {
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
tolerance_zone_definition_with_per_unit_size_specification *tolerance_zone_definition_with_per_unit_size_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_zone_definition_with_per_unit_size_specification *>(s);
      }
   return NULL;
   }
tolerance_zone_definition_with_per_unit_size_specification *tolerance_zone_definition_with_per_unit_size_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_zone_definition_with_per_unit_size_specification *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_zone_definition_with_per_unit_size_specification *tolerance_zone_definition_with_per_unit_size_specification::Construct() {
   tolerance_zone_definition_with_per_unit_size_specification *result = NULL;

   // create the tolerance_zone_definition_with_per_unit_size_specification.
   result = new tolerance_zone_definition_with_per_unit_size_specification();
   return result;
   }
bool tolerance_zone_definition_with_per_unit_size_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_zone_definition_with_per_unit_size_specification\r\n");

   // Check for the existence of all required attributes
   if (_per_unit_size_specification == NULL) {
      TRACE("ERROR: _per_unit_size_specification a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (tolerance_zone_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
