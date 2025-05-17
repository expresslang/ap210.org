// Source for AP210 application object
//     conical_tolerance_zone_boundary_diametrical_size_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "conical_tolerance_zone_boundary_diametrical_size_characteristic.h"

// Classes
#include <conical_tolerance_zone_boundary_and_surface_relationship.h>
#include <length_data_element.h>

conical_tolerance_zone_boundary_diametrical_size_characteristic::conical_tolerance_zone_boundary_diametrical_size_characteristic() {
   initialize();
   }
conical_tolerance_zone_boundary_diametrical_size_characteristic::~conical_tolerance_zone_boundary_diametrical_size_characteristic() {
   // Free string attributes
   }
// intialize data members
void conical_tolerance_zone_boundary_diametrical_size_characteristic::initialize() {
   // Required attributes
   _sized_boundary_at_surface = NULL;
   _tolerance_value = NULL;

   // Optional attributes
   }
// Runtime type identification
int conical_tolerance_zone_boundary_diametrical_size_characteristic::DynamicType(int ID) {
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
conical_tolerance_zone_boundary_diametrical_size_characteristic *conical_tolerance_zone_boundary_diametrical_size_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conical_tolerance_zone_boundary_diametrical_size_characteristic *>(s);
      }
   return NULL;
   }
conical_tolerance_zone_boundary_diametrical_size_characteristic *conical_tolerance_zone_boundary_diametrical_size_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conical_tolerance_zone_boundary_diametrical_size_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
conical_tolerance_zone_boundary_diametrical_size_characteristic *conical_tolerance_zone_boundary_diametrical_size_characteristic::Construct() {
   conical_tolerance_zone_boundary_diametrical_size_characteristic *result = NULL;

   // create the conical_tolerance_zone_boundary_diametrical_size_characteristic.
   result = new conical_tolerance_zone_boundary_diametrical_size_characteristic();
   return result;
   }
bool conical_tolerance_zone_boundary_diametrical_size_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conical_tolerance_zone_boundary_diametrical_size_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_sized_boundary_at_surface == NULL) {
      TRACE("ERROR: _sized_boundary_at_surface a required attribute is NULL!\r\n");
      result = false;
      }
   if (_tolerance_value == NULL) {
      TRACE("ERROR: _tolerance_value a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
