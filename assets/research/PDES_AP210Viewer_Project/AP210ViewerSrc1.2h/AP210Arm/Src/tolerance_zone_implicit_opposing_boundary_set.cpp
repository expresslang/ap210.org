// Source for AP210 application object
//     tolerance_zone_implicit_opposing_boundary_set

// Precompiled include files
#include <StdAfx.h>

#include "tolerance_zone_implicit_opposing_boundary_set.h"

// Classes

tolerance_zone_implicit_opposing_boundary_set::tolerance_zone_implicit_opposing_boundary_set() {
   initialize();
   }
tolerance_zone_implicit_opposing_boundary_set::~tolerance_zone_implicit_opposing_boundary_set() {
   // Free string attributes
   }
// intialize data members
void tolerance_zone_implicit_opposing_boundary_set::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int tolerance_zone_implicit_opposing_boundary_set::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = tolerance_zone_opposing_boundary_set::DynamicType(ID);
      }
   return result;
   }
tolerance_zone_implicit_opposing_boundary_set *tolerance_zone_implicit_opposing_boundary_set::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<tolerance_zone_implicit_opposing_boundary_set *>(s);
      }
   return NULL;
   }
tolerance_zone_implicit_opposing_boundary_set *tolerance_zone_implicit_opposing_boundary_set::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<tolerance_zone_implicit_opposing_boundary_set *>(s);
      }
   return NULL;
   }
// construction factory
tolerance_zone_implicit_opposing_boundary_set *tolerance_zone_implicit_opposing_boundary_set::Construct() {
   tolerance_zone_implicit_opposing_boundary_set *result = NULL;

   // create the tolerance_zone_implicit_opposing_boundary_set.
   result = new tolerance_zone_implicit_opposing_boundary_set();
   return result;
   }
bool tolerance_zone_implicit_opposing_boundary_set::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: tolerance_zone_implicit_opposing_boundary_set\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (tolerance_zone_opposing_boundary_set::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
