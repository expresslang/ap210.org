// Source for AP210 application object
//     flatness_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "flatness_tolerance.h"

// Classes

flatness_tolerance::flatness_tolerance() {
   initialize();
   }
flatness_tolerance::~flatness_tolerance() {
   // Free string attributes
   }
// intialize data members
void flatness_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int flatness_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = geometric_tolerance_without_referenced_datum_system::DynamicType(ID);
      }
   return result;
   }
flatness_tolerance *flatness_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<flatness_tolerance *>(s);
      }
   return NULL;
   }
flatness_tolerance *flatness_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<flatness_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
flatness_tolerance *flatness_tolerance::Construct() {
   flatness_tolerance *result = NULL;

   // create the flatness_tolerance.
   result = new flatness_tolerance();
   return result;
   }
bool flatness_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: flatness_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_without_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
