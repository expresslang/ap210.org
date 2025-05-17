// Source for AP210 application object
//     curve_style_font_and_scaling

// Precompiled include files
#include <StdAfx.h>

#include "curve_style_font_and_scaling.h"

// Classes
#include <positive_ratio_measure.h>

curve_style_font_and_scaling::curve_style_font_and_scaling() {
   initialize();
   }
curve_style_font_and_scaling::~curve_style_font_and_scaling() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void curve_style_font_and_scaling::initialize() {
   // Required attributes
   _name = NULL;
   _curve_font_scaling = NULL;

   // Optional attributes
   }
// Runtime type identification
int curve_style_font_and_scaling::DynamicType(int ID) {
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
curve_style_font_and_scaling *curve_style_font_and_scaling::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<curve_style_font_and_scaling *>(s);
      }
   return NULL;
   }
curve_style_font_and_scaling *curve_style_font_and_scaling::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<curve_style_font_and_scaling *>(s);
      }
   return NULL;
   }
// construction factory
curve_style_font_and_scaling *curve_style_font_and_scaling::Construct() {
   curve_style_font_and_scaling *result = NULL;

   // create the curve_style_font_and_scaling.
   result = new curve_style_font_and_scaling();
   return result;
   }
bool curve_style_font_and_scaling::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: curve_style_font_and_scaling\r\n");

   // Check for the existence of all required attributes
   if (_curve_font == NULL) {
      TRACE("ERROR: _curve_font a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_curve_font_scaling == NULL) {
      TRACE("ERROR: _curve_font_scaling a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
