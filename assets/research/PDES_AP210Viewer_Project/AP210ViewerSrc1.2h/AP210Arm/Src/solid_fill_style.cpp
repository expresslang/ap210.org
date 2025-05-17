// Source for AP210 application object
//     solid_fill_style

// Precompiled include files
#include <StdAfx.h>

#include "solid_fill_style.h"

// Classes

solid_fill_style::solid_fill_style() {
   initialize();
   }
solid_fill_style::~solid_fill_style() {
   // Free string attributes
   }
// intialize data members
void solid_fill_style::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int solid_fill_style::DynamicType(int ID) {
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
solid_fill_style *solid_fill_style::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<solid_fill_style *>(s);
      }
   return NULL;
   }
solid_fill_style *solid_fill_style::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<solid_fill_style *>(s);
      }
   return NULL;
   }
// construction factory
solid_fill_style *solid_fill_style::Construct() {
   solid_fill_style *result = NULL;

   // create the solid_fill_style.
   result = new solid_fill_style();
   return result;
   }
bool solid_fill_style::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: solid_fill_style\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
