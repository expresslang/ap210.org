// Source for AP210 application object
//     datum_axis_and_tolerance_zone_orienting_relationship

// Precompiled include files
#include <StdAfx.h>

#include "datum_axis_and_tolerance_zone_orienting_relationship.h"

// Classes
#include <tolerance_zone.h>
#include <datum_axis.h>

datum_axis_and_tolerance_zone_orienting_relationship::datum_axis_and_tolerance_zone_orienting_relationship() {
   initialize();
   }
datum_axis_and_tolerance_zone_orienting_relationship::~datum_axis_and_tolerance_zone_orienting_relationship() {
   // Free string attributes
   }
// intialize data members
void datum_axis_and_tolerance_zone_orienting_relationship::initialize() {
   // Required attributes
   _oriented_tolerance_zone = NULL;
   _orienting_datum_axis = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_axis_and_tolerance_zone_orienting_relationship::DynamicType(int ID) {
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
datum_axis_and_tolerance_zone_orienting_relationship *datum_axis_and_tolerance_zone_orienting_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_axis_and_tolerance_zone_orienting_relationship *>(s);
      }
   return NULL;
   }
datum_axis_and_tolerance_zone_orienting_relationship *datum_axis_and_tolerance_zone_orienting_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_axis_and_tolerance_zone_orienting_relationship *>(s);
      }
   return NULL;
   }
// construction factory
datum_axis_and_tolerance_zone_orienting_relationship *datum_axis_and_tolerance_zone_orienting_relationship::Construct() {
   datum_axis_and_tolerance_zone_orienting_relationship *result = NULL;

   // create the datum_axis_and_tolerance_zone_orienting_relationship.
   result = new datum_axis_and_tolerance_zone_orienting_relationship();
   return result;
   }
bool datum_axis_and_tolerance_zone_orienting_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_axis_and_tolerance_zone_orienting_relationship\r\n");

   // Check for the existence of all required attributes
   if (_oriented_tolerance_zone == NULL) {
      TRACE("ERROR: _oriented_tolerance_zone a required attribute is NULL!\r\n");
      result = false;
      }
   if (_orienting_datum_axis == NULL) {
      TRACE("ERROR: _orienting_datum_axis a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
