// Source for AP210 application object
//     boundary_zone_definition_with_specified_size

// Precompiled include files
#include <StdAfx.h>

#include "boundary_zone_definition_with_specified_size.h"

// Classes
#include <boundary_size_characteristic.h>

boundary_zone_definition_with_specified_size::boundary_zone_definition_with_specified_size() {
   initialize();
   }
boundary_zone_definition_with_specified_size::~boundary_zone_definition_with_specified_size() {
   // Free string attributes
   }
// intialize data members
void boundary_zone_definition_with_specified_size::initialize() {
   // Required attributes
   _specified_boundary_size = NULL;

   // Optional attributes
   }
// Runtime type identification
int boundary_zone_definition_with_specified_size::DynamicType(int ID) {
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
boundary_zone_definition_with_specified_size *boundary_zone_definition_with_specified_size::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<boundary_zone_definition_with_specified_size *>(s);
      }
   return NULL;
   }
boundary_zone_definition_with_specified_size *boundary_zone_definition_with_specified_size::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<boundary_zone_definition_with_specified_size *>(s);
      }
   return NULL;
   }
// construction factory
boundary_zone_definition_with_specified_size *boundary_zone_definition_with_specified_size::Construct() {
   boundary_zone_definition_with_specified_size *result = NULL;

   // create the boundary_zone_definition_with_specified_size.
   result = new boundary_zone_definition_with_specified_size();
   return result;
   }
bool boundary_zone_definition_with_specified_size::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: boundary_zone_definition_with_specified_size\r\n");

   // Check for the existence of all required attributes
   if (_specified_boundary_size == NULL) {
      TRACE("ERROR: _specified_boundary_size a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (tolerance_zone_boundary_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
