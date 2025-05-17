// Source for AP210 application object
//     physical_unit_relationship

// Precompiled include files
#include <StdAfx.h>

#include "physical_unit_relationship.h"

// Classes
#include <physical_unit.h>
#include <physical_unit.h>

physical_unit_relationship::physical_unit_relationship() {
   initialize();
   }
physical_unit_relationship::~physical_unit_relationship() {
   // Free string attributes
   }
// intialize data members
void physical_unit_relationship::initialize() {
   // Required attributes
   _relating_unit = NULL;
   _related_unit = NULL;

   // Optional attributes
   }
// Runtime type identification
int physical_unit_relationship::DynamicType(int ID) {
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
physical_unit_relationship *physical_unit_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_unit_relationship *>(s);
      }
   return NULL;
   }
physical_unit_relationship *physical_unit_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_unit_relationship *>(s);
      }
   return NULL;
   }
// construction factory
physical_unit_relationship *physical_unit_relationship::Construct() {
   physical_unit_relationship *result = NULL;

   // create the physical_unit_relationship.
   result = new physical_unit_relationship();
   return result;
   }
bool physical_unit_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_unit_relationship\r\n");

   // Check for the existence of all required attributes
   if (_relating_unit == NULL) {
      TRACE("ERROR: _relating_unit a required attribute is NULL!\r\n");
      result = false;
      }
   if (_related_unit == NULL) {
      TRACE("ERROR: _related_unit a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
