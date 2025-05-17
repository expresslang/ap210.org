// Source for AP210 application object
//     dimensional_characteristic_representation

// Precompiled include files
#include <StdAfx.h>

#include "dimensional_characteristic_representation.h"

// Classes
#include <shape_dimension_representation.h>

dimensional_characteristic_representation::dimensional_characteristic_representation() {
   initialize();
   }
dimensional_characteristic_representation::~dimensional_characteristic_representation() {
   // Free string attributes
   }
// intialize data members
void dimensional_characteristic_representation::initialize() {
   // Required attributes
   _representation = NULL;

   // Optional attributes
   }
// Runtime type identification
int dimensional_characteristic_representation::DynamicType(int ID) {
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
dimensional_characteristic_representation *dimensional_characteristic_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimensional_characteristic_representation *>(s);
      }
   return NULL;
   }
dimensional_characteristic_representation *dimensional_characteristic_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimensional_characteristic_representation *>(s);
      }
   return NULL;
   }
// construction factory
dimensional_characteristic_representation *dimensional_characteristic_representation::Construct() {
   dimensional_characteristic_representation *result = NULL;

   // create the dimensional_characteristic_representation.
   result = new dimensional_characteristic_representation();
   return result;
   }
bool dimensional_characteristic_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimensional_characteristic_representation\r\n");

   // Check for the existence of all required attributes
   if (_representation == NULL) {
      TRACE("ERROR: _representation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_dimension == NULL) {
      TRACE("ERROR: _dimension a required attribute is NULL!\r\n");
      result = false;
      }
   if (_auxiliary_dimension_representation == NULL) {
      TRACE("ERROR: _auxiliary_dimension_representation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
