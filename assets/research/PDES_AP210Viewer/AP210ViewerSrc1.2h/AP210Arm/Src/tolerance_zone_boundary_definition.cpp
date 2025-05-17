// Source for AP210 application object
//     tolerance_zone_boundary_definition

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_zone_boundary_definition.h"

// Classes
#include <tolerance_zone_boundary.h>

tolerance_zone_boundary_definition::tolerance_zone_boundary_definition() {
   initialize();
   }
tolerance_zone_boundary_definition::~tolerance_zone_boundary_definition() {
   // Free string attributes
   }
// intialize data members
void tolerance_zone_boundary_definition::initialize() {
   // Required attributes
   _defined_zone_boundary = NULL;

   // Optional attributes
   }
// Runtime type identification
int tolerance_zone_boundary_definition::DynamicType(int ID) {
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
tolerance_zone_boundary_definition *tolerance_zone_boundary_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_zone_boundary_definition *>(s);
      }
   return NULL;
   }
tolerance_zone_boundary_definition *tolerance_zone_boundary_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_zone_boundary_definition *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_zone_boundary_definition *tolerance_zone_boundary_definition::Construct() {
   tolerance_zone_boundary_definition *result = NULL;

   // create the tolerance_zone_boundary_definition.
   result = new tolerance_zone_boundary_definition();
   return result;
   }
bool tolerance_zone_boundary_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_zone_boundary_definition\r\n");

   // Check for the existence of all required attributes
   if (_defined_zone_boundary == NULL) {
      TRACE("ERROR: _defined_zone_boundary a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
