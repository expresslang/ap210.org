// Source for AP210 application object
//     perpendicularity_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "perpendicularity_tolerance.h"

// Classes

perpendicularity_tolerance::perpendicularity_tolerance() {
   initialize();
   }
perpendicularity_tolerance::~perpendicularity_tolerance() {
   // Free string attributes
   }
// intialize data members
void perpendicularity_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int perpendicularity_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = geometric_tolerance_with_referenced_datum_system::DynamicType(ID);
      }
   return result;
   }
perpendicularity_tolerance *perpendicularity_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<perpendicularity_tolerance *>(s);
      }
   return NULL;
   }
perpendicularity_tolerance *perpendicularity_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<perpendicularity_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
perpendicularity_tolerance *perpendicularity_tolerance::Construct() {
   perpendicularity_tolerance *result = NULL;

   // create the perpendicularity_tolerance.
   result = new perpendicularity_tolerance();
   return result;
   }
bool perpendicularity_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: perpendicularity_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_with_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
