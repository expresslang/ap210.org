// Source for AP210 application object
//     styled_curve_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "styled_curve_occurrence.h"

// Classes
#include <curve.h>
#include <curve_style.h>

styled_curve_occurrence::styled_curve_occurrence() {
   initialize();
   }
styled_curve_occurrence::~styled_curve_occurrence() {
   // Free string attributes
   }
// intialize data members
void styled_curve_occurrence::initialize() {
   // Required attributes
   _styled_curve = NULL;
   _of_curve_style = NULL;

   // Optional attributes
   }
// Runtime type identification
int styled_curve_occurrence::DynamicType(int ID) {
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
styled_curve_occurrence *styled_curve_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<styled_curve_occurrence *>(s);
      }
   return NULL;
   }
styled_curve_occurrence *styled_curve_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<styled_curve_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
styled_curve_occurrence *styled_curve_occurrence::Construct() {
   styled_curve_occurrence *result = NULL;

   // create the styled_curve_occurrence.
   result = new styled_curve_occurrence();
   return result;
   }
bool styled_curve_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: styled_curve_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_styled_curve == NULL) {
      TRACE("ERROR: _styled_curve a required attribute is NULL!\r\n");
      result = false;
      }
   if (_of_curve_style == NULL) {
      TRACE("ERROR: _of_curve_style a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
