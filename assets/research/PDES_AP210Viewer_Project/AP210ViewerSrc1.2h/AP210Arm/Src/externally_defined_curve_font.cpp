// Source for AP210 application object
//     externally_defined_curve_font

// Precompiled include files
#include <StdAfx.h>

#include "externally_defined_curve_font.h"

// Classes

externally_defined_curve_font::externally_defined_curve_font() {
   initialize();
   }
externally_defined_curve_font::~externally_defined_curve_font() {
   // Free string attributes
   }
// intialize data members
void externally_defined_curve_font::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int externally_defined_curve_font::DynamicType(int ID) {
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
externally_defined_curve_font *externally_defined_curve_font::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<externally_defined_curve_font *>(s);
      }
   return NULL;
   }
externally_defined_curve_font *externally_defined_curve_font::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<externally_defined_curve_font *>(s);
      }
   return NULL;
   }
// construction factory
externally_defined_curve_font *externally_defined_curve_font::Construct() {
   externally_defined_curve_font *result = NULL;

   // create the externally_defined_curve_font.
   result = new externally_defined_curve_font();
   return result;
   }
bool externally_defined_curve_font::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: externally_defined_curve_font\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
