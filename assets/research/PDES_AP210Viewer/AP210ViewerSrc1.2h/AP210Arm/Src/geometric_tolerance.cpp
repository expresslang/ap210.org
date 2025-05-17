// Source for AP210 application object
//     geometric_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "geometric_tolerance.h"

// Classes

geometric_tolerance::geometric_tolerance() {
   initialize();
   }
geometric_tolerance::~geometric_tolerance() {
   // Free string attributes
   }
// intialize data members
void geometric_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int geometric_tolerance::DynamicType(int ID) {
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
geometric_tolerance *geometric_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<geometric_tolerance *>(s);
      }
   return NULL;
   }
geometric_tolerance *geometric_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<geometric_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
geometric_tolerance *geometric_tolerance::Construct() {
   geometric_tolerance *result = NULL;

   // create the geometric_tolerance.
   result = new geometric_tolerance();
   return result;
   }
bool geometric_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: geometric_tolerance\r\n");

   // Check for the existence of all required attributes
   if (_tolerance_zone_or_boundary_definition == NULL) {
      TRACE("ERROR: _tolerance_zone_or_boundary_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_toleranced_shape_element == NULL) {
      TRACE("ERROR: _toleranced_shape_element a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
