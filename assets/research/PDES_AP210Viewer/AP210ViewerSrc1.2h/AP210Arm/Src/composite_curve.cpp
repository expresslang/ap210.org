// Source for AP210 application object
//     composite_curve

// Precompiled include files
#include <StdAfx.h>

#include "composite_curve.h"

// Classes

composite_curve::composite_curve() {
   initialize();
   }
composite_curve::~composite_curve() {
   // Free string attributes
   }
// intialize data members
void composite_curve::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int composite_curve::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = curve::DynamicType(ID);
      }
   return result;
   }
composite_curve *composite_curve::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<composite_curve *>(s);
      }
   return NULL;
   }
composite_curve *composite_curve::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<composite_curve *>(s);
      }
   return NULL;
   }
// construction factory
composite_curve *composite_curve::Construct() {
   composite_curve *result = NULL;

   // create the composite_curve.
   result = new composite_curve();
   return result;
   }
bool composite_curve::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: composite_curve\r\n");

   // Check for the existence of all required attributes
   if (_curve_segment == NULL) {
      TRACE("ERROR: _curve_segment a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (curve::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
