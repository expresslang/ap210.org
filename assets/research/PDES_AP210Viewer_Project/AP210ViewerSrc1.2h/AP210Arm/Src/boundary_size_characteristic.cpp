// Source for AP210 application object
//     boundary_size_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "boundary_size_characteristic.h"

// Classes
#include <length_data_element.h>
#include <length_data_element.h>

boundary_size_characteristic::boundary_size_characteristic() {
   initialize();
   }
boundary_size_characteristic::~boundary_size_characteristic() {
   // Free string attributes
   }
// intialize data members
void boundary_size_characteristic::initialize() {
   // Required attributes
   _tolerance_value = NULL;

   // Optional attributes
   _maximum_tolerance_value = NULL;
   }
// Runtime type identification
int boundary_size_characteristic::DynamicType(int ID) {
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
boundary_size_characteristic *boundary_size_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<boundary_size_characteristic *>(s);
      }
   return NULL;
   }
boundary_size_characteristic *boundary_size_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<boundary_size_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
boundary_size_characteristic *boundary_size_characteristic::Construct() {
   boundary_size_characteristic *result = NULL;

   // create the boundary_size_characteristic.
   result = new boundary_size_characteristic();
   return result;
   }
bool boundary_size_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: boundary_size_characteristic\r\n");

   // Check for the existence of all required attributes
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
