// Source for AP210 application object
//     planned_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "planned_characteristic.h"

// Classes
#include <coordinated_characteristic.h>

planned_characteristic::planned_characteristic() {
   initialize();
   }
planned_characteristic::~planned_characteristic() {
   // Free string attributes
   }
// intialize data members
void planned_characteristic::initialize() {
   // Required attributes
   _planned_coordinated_characteristic = NULL;

   // Optional attributes
   }
// Runtime type identification
int planned_characteristic::DynamicType(int ID) {
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
planned_characteristic *planned_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<planned_characteristic *>(s);
      }
   return NULL;
   }
planned_characteristic *planned_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<planned_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
planned_characteristic *planned_characteristic::Construct() {
   planned_characteristic *result = NULL;

   // create the planned_characteristic.
   result = new planned_characteristic();
   return result;
   }
bool planned_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: planned_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_reference_requirement == NULL) {
      TRACE("ERROR: _reference_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_planned_coordinated_characteristic == NULL) {
      TRACE("ERROR: _planned_coordinated_characteristic a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
