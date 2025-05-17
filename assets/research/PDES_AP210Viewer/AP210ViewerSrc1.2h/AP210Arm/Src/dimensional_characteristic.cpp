// Source for AP210 application object
//     dimensional_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "dimensional_characteristic.h"

// Classes

dimensional_characteristic::dimensional_characteristic() {
   initialize();
   }
dimensional_characteristic::~dimensional_characteristic() {
   // Free string attributes
   }
// intialize data members
void dimensional_characteristic::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int dimensional_characteristic::DynamicType(int ID) {
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
dimensional_characteristic *dimensional_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimensional_characteristic *>(s);
      }
   return NULL;
   }
dimensional_characteristic *dimensional_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimensional_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
dimensional_characteristic *dimensional_characteristic::Construct() {
   dimensional_characteristic *result = NULL;

   // create the dimensional_characteristic.
   result = new dimensional_characteristic();
   return result;
   }
bool dimensional_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimensional_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_dimension_type == NULL) {
      TRACE("ERROR: _dimension_type a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
