// Source for AP210 application object
//     geometric_alignment

// Precompiled include files
#include <StdAfx.h>

#include "geometric_alignment.h"

// Classes

geometric_alignment::geometric_alignment() {
   initialize();
   }
geometric_alignment::~geometric_alignment() {
   // Free string attributes
   }
// intialize data members
void geometric_alignment::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int geometric_alignment::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = derived_shape_element::DynamicType(ID);
      }
   return result;
   }
geometric_alignment *geometric_alignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<geometric_alignment *>(s);
      }
   return NULL;
   }
geometric_alignment *geometric_alignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<geometric_alignment *>(s);
      }
   return NULL;
   }
// construction factory
geometric_alignment *geometric_alignment::Construct() {
   geometric_alignment *result = NULL;

   // create the geometric_alignment.
   result = new geometric_alignment();
   return result;
   }
bool geometric_alignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: geometric_alignment\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (derived_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
