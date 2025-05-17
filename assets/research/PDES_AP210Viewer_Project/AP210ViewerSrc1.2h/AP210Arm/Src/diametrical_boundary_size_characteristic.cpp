// Source for AP210 application object
//     diametrical_boundary_size_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "diametrical_boundary_size_characteristic.h"

// Classes
#include <tolerance_zone_circular_or_cylindrical_or_spherical_boundary.h>

diametrical_boundary_size_characteristic::diametrical_boundary_size_characteristic() {
   initialize();
   }
diametrical_boundary_size_characteristic::~diametrical_boundary_size_characteristic() {
   // Free string attributes
   }
// intialize data members
void diametrical_boundary_size_characteristic::initialize() {
   // Required attributes
   _sized_boundary = NULL;

   // Optional attributes
   }
// Runtime type identification
int diametrical_boundary_size_characteristic::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = boundary_size_characteristic::DynamicType(ID);
      }
   return result;
   }
diametrical_boundary_size_characteristic *diametrical_boundary_size_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<diametrical_boundary_size_characteristic *>(s);
      }
   return NULL;
   }
diametrical_boundary_size_characteristic *diametrical_boundary_size_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<diametrical_boundary_size_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
diametrical_boundary_size_characteristic *diametrical_boundary_size_characteristic::Construct() {
   diametrical_boundary_size_characteristic *result = NULL;

   // create the diametrical_boundary_size_characteristic.
   result = new diametrical_boundary_size_characteristic();
   return result;
   }
bool diametrical_boundary_size_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: diametrical_boundary_size_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_sized_boundary == NULL) {
      TRACE("ERROR: _sized_boundary a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (boundary_size_characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
