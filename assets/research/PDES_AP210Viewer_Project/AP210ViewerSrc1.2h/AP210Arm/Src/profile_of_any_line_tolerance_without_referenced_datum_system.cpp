// Source for AP210 application object
//     profile_of_any_line_tolerance_without_referenced_datum_system

// Precompiled include files
#include <StdAfx.h>

#include "profile_of_any_line_tolerance_without_referenced_datum_system.h"

// Classes

profile_of_any_line_tolerance_without_referenced_datum_system::profile_of_any_line_tolerance_without_referenced_datum_system() {
   initialize();
   }
profile_of_any_line_tolerance_without_referenced_datum_system::~profile_of_any_line_tolerance_without_referenced_datum_system() {
   // Free string attributes
   }
// intialize data members
void profile_of_any_line_tolerance_without_referenced_datum_system::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int profile_of_any_line_tolerance_without_referenced_datum_system::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = profile_of_any_line_tolerance::DynamicType(ID);
      }
   if (result == 0) {
      result = geometric_tolerance_without_referenced_datum_system::DynamicType(ID);
      }
   return result;
   }
profile_of_any_line_tolerance_without_referenced_datum_system *profile_of_any_line_tolerance_without_referenced_datum_system::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<profile_of_any_line_tolerance_without_referenced_datum_system *>(s);
      }
   return NULL;
   }
profile_of_any_line_tolerance_without_referenced_datum_system *profile_of_any_line_tolerance_without_referenced_datum_system::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<profile_of_any_line_tolerance_without_referenced_datum_system *>(s);
      }
   return NULL;
   }
// construction factory
profile_of_any_line_tolerance_without_referenced_datum_system *profile_of_any_line_tolerance_without_referenced_datum_system::Construct() {
   profile_of_any_line_tolerance_without_referenced_datum_system *result = NULL;

   // create the profile_of_any_line_tolerance_without_referenced_datum_system.
   result = new profile_of_any_line_tolerance_without_referenced_datum_system();
   return result;
   }
bool profile_of_any_line_tolerance_without_referenced_datum_system::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: profile_of_any_line_tolerance_without_referenced_datum_system\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (profile_of_any_line_tolerance::hasRequiredAttributes() == false) {
      result = false;
      }
   if (geometric_tolerance_without_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
