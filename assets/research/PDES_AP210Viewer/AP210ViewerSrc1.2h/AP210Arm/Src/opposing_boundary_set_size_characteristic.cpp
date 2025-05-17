// Source for AP210 application object
//     opposing_boundary_set_size_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "opposing_boundary_set_size_characteristic.h"

// Classes
#include <tolerance_zone_opposing_boundary_set.h>

opposing_boundary_set_size_characteristic::opposing_boundary_set_size_characteristic() {
   initialize();
   }
opposing_boundary_set_size_characteristic::~opposing_boundary_set_size_characteristic() {
   // Free string attributes
   }
// intialize data members
void opposing_boundary_set_size_characteristic::initialize() {
   // Required attributes
   _sized_boundary_set = NULL;

   // Optional attributes
   }
// Runtime type identification
int opposing_boundary_set_size_characteristic::DynamicType(int ID) {
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
opposing_boundary_set_size_characteristic *opposing_boundary_set_size_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<opposing_boundary_set_size_characteristic *>(s);
      }
   return NULL;
   }
opposing_boundary_set_size_characteristic *opposing_boundary_set_size_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<opposing_boundary_set_size_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
opposing_boundary_set_size_characteristic *opposing_boundary_set_size_characteristic::Construct() {
   opposing_boundary_set_size_characteristic *result = NULL;

   // create the opposing_boundary_set_size_characteristic.
   result = new opposing_boundary_set_size_characteristic();
   return result;
   }
bool opposing_boundary_set_size_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: opposing_boundary_set_size_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_sized_boundary_set == NULL) {
      TRACE("ERROR: _sized_boundary_set a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (boundary_size_characteristic::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
