// Source for AP210 application object
//     axis_placement

// Precompiled include files
#include <StdAfx.h>

#include "axis_placement.h"

// Classes
#include <orientation.h>
#include <cartesian_point.h>

axis_placement::axis_placement() {
   initialize();
   }
axis_placement::~axis_placement() {
   // Free string attributes
   }
// intialize data members
void axis_placement::initialize() {
   // Required attributes
   _device_orientation = NULL;
   _translation = NULL;

   // Optional attributes
   }
// Runtime type identification
int axis_placement::DynamicType(int ID) {
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
axis_placement *axis_placement::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<axis_placement *>(s);
      }
   return NULL;
   }
axis_placement *axis_placement::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<axis_placement *>(s);
      }
   return NULL;
   }
// construction factory
axis_placement *axis_placement::Construct() {
   axis_placement *result = NULL;

   // create the axis_placement.
   result = new axis_placement();
   return result;
   }
bool axis_placement::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: axis_placement\r\n");

   // Check for the existence of all required attributes
   if (_device_orientation == NULL) {
      TRACE("ERROR: _device_orientation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_translation == NULL) {
      TRACE("ERROR: _translation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
