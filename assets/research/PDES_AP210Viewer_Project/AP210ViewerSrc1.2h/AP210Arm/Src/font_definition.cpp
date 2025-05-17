// Source for AP210 application object
//     font_definition

// Precompiled include files
#include <StdAfx.h>

#include "font_definition.h"

// Classes

font_definition::font_definition() {
   initialize();
   }
font_definition::~font_definition() {
   // Free string attributes
   }
// intialize data members
void font_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int font_definition::DynamicType(int ID) {
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
font_definition *font_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<font_definition *>(s);
      }
   return NULL;
   }
font_definition *font_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<font_definition *>(s);
      }
   return NULL;
   }
// construction factory
font_definition *font_definition::Construct() {
   font_definition *result = NULL;

   // create the font_definition.
   result = new font_definition();
   return result;
   }
bool font_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: font_definition\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
