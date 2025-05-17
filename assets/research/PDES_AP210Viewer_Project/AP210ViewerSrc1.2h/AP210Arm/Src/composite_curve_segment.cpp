// Source for AP210 application object
//     composite_curve_segment

// Precompiled include files
#include <StdAfx.h>

#include "composite_curve_segment.h"

// Classes
#include <curve.h>

composite_curve_segment::composite_curve_segment() {
   initialize();
   }
composite_curve_segment::~composite_curve_segment() {
   // Free string attributes
   }
// intialize data members
void composite_curve_segment::initialize() {
   // Required attributes
   _segment_curve = NULL;

   // Optional attributes
   }
// Runtime type identification
int composite_curve_segment::DynamicType(int ID) {
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
composite_curve_segment *composite_curve_segment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<composite_curve_segment *>(s);
      }
   return NULL;
   }
composite_curve_segment *composite_curve_segment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<composite_curve_segment *>(s);
      }
   return NULL;
   }
// construction factory
composite_curve_segment *composite_curve_segment::Construct() {
   composite_curve_segment *result = NULL;

   // create the composite_curve_segment.
   result = new composite_curve_segment();
   return result;
   }
bool composite_curve_segment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: composite_curve_segment\r\n");

   // Check for the existence of all required attributes
   if (_segment_curve == NULL) {
      TRACE("ERROR: _segment_curve a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
