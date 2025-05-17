// Source for AP210 application object
//     datum_axis_related_orientation

// Precompiled include files
#include <StdAfx.h>

#include "datum_axis_related_orientation.h"

// Classes
#include <datum_axis_and_tolerance_zone_orienting_relationship.h>

datum_axis_related_orientation::datum_axis_related_orientation() {
   initialize();
   }
datum_axis_related_orientation::~datum_axis_related_orientation() {
   // Free string attributes
   }
// intialize data members
void datum_axis_related_orientation::initialize() {
   // Required attributes
   _orienting_relationship = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_axis_related_orientation::DynamicType(int ID) {
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
datum_axis_related_orientation *datum_axis_related_orientation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_axis_related_orientation *>(s);
      }
   return NULL;
   }
datum_axis_related_orientation *datum_axis_related_orientation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_axis_related_orientation *>(s);
      }
   return NULL;
   }
// construction factory
datum_axis_related_orientation *datum_axis_related_orientation::Construct() {
   datum_axis_related_orientation *result = NULL;

   // create the datum_axis_related_orientation.
   result = new datum_axis_related_orientation();
   return result;
   }
bool datum_axis_related_orientation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_axis_related_orientation\r\n");

   // Check for the existence of all required attributes
   if (_orienting_relationship == NULL) {
      TRACE("ERROR: _orienting_relationship a required attribute is NULL!\r\n");
      result = false;
      }
   if (_orientation_type == NULL) {
      TRACE("ERROR: _orientation_type a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
