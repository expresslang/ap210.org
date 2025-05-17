// Source for AP210 application object
//     curve_style_font

// Precompiled include files
#include <StdAfx.h>

#include "curve_style_font.h"

// Classes

curve_style_font::curve_style_font() {
   initialize();
   }
curve_style_font::~curve_style_font() {
   // Free string attributes
   }
// intialize data members
void curve_style_font::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int curve_style_font::DynamicType(int ID) {
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
curve_style_font *curve_style_font::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<curve_style_font *>(s);
      }
   return NULL;
   }
curve_style_font *curve_style_font::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<curve_style_font *>(s);
      }
   return NULL;
   }
// construction factory
curve_style_font *curve_style_font::Construct() {
   curve_style_font *result = NULL;

   // create the curve_style_font.
   result = new curve_style_font();
   return result;
   }
bool curve_style_font::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: curve_style_font\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
