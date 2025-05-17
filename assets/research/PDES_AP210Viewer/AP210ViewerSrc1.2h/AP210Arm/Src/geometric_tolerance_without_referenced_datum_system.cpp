// Source for AP210 application object
//     geometric_tolerance_without_referenced_datum_system

// Precompiled include files
#include <StdAfx.h>

#include "geometric_tolerance_without_referenced_datum_system.h"

// Classes

geometric_tolerance_without_referenced_datum_system::geometric_tolerance_without_referenced_datum_system() {
   initialize();
   }
geometric_tolerance_without_referenced_datum_system::~geometric_tolerance_without_referenced_datum_system() {
   // Free string attributes
   }
// intialize data members
void geometric_tolerance_without_referenced_datum_system::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int geometric_tolerance_without_referenced_datum_system::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = geometric_tolerance::DynamicType(ID);
      }
   return result;
   }
geometric_tolerance_without_referenced_datum_system *geometric_tolerance_without_referenced_datum_system::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<geometric_tolerance_without_referenced_datum_system *>(s);
      }
   return NULL;
   }
geometric_tolerance_without_referenced_datum_system *geometric_tolerance_without_referenced_datum_system::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<geometric_tolerance_without_referenced_datum_system *>(s);
      }
   return NULL;
   }
// construction factory
geometric_tolerance_without_referenced_datum_system *geometric_tolerance_without_referenced_datum_system::Construct() {
   geometric_tolerance_without_referenced_datum_system *result = NULL;

   // create the geometric_tolerance_without_referenced_datum_system.
   result = new geometric_tolerance_without_referenced_datum_system();
   return result;
   }
bool geometric_tolerance_without_referenced_datum_system::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: geometric_tolerance_without_referenced_datum_system\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
