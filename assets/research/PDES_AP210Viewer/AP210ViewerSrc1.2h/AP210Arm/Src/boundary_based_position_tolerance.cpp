// Source for AP210 application object
//     boundary_based_position_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "boundary_based_position_tolerance.h"

// Classes
#include <profile_of_any_surface_tolerance_with_referenced_datum_system.h>

boundary_based_position_tolerance::boundary_based_position_tolerance() {
   initialize();
   }
boundary_based_position_tolerance::~boundary_based_position_tolerance() {
   // Free string attributes
   }
// intialize data members
void boundary_based_position_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   _profile_control = NULL;
   }
// Runtime type identification
int boundary_based_position_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = position_tolerance_with_referenced_datum_system::DynamicType(ID);
      }
   if (result == 0) {
      result = geometric_tolerance_with_applied_material_condition_property::DynamicType(ID);
      }
   return result;
   }
boundary_based_position_tolerance *boundary_based_position_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<boundary_based_position_tolerance *>(s);
      }
   return NULL;
   }
boundary_based_position_tolerance *boundary_based_position_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<boundary_based_position_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
boundary_based_position_tolerance *boundary_based_position_tolerance::Construct() {
   boundary_based_position_tolerance *result = NULL;

   // create the boundary_based_position_tolerance.
   result = new boundary_based_position_tolerance();
   return result;
   }
bool boundary_based_position_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: boundary_based_position_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (position_tolerance_with_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   if (geometric_tolerance_with_applied_material_condition_property::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
