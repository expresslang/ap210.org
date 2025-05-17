// Source for AP210 application object
//     position_tolerance_without_referenced_datum_system

// Precompiled include files
#include <StdAfx.h>

#include "position_tolerance_without_referenced_datum_system.h"

// Classes

position_tolerance_without_referenced_datum_system::position_tolerance_without_referenced_datum_system() {
   initialize();
   }
position_tolerance_without_referenced_datum_system::~position_tolerance_without_referenced_datum_system() {
   // Free string attributes
   }
// intialize data members
void position_tolerance_without_referenced_datum_system::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int position_tolerance_without_referenced_datum_system::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = position_tolerance::DynamicType(ID);
      }
   if (result == 0) {
      result = geometric_tolerance_without_referenced_datum_system::DynamicType(ID);
      }
   return result;
   }
position_tolerance_without_referenced_datum_system *position_tolerance_without_referenced_datum_system::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<position_tolerance_without_referenced_datum_system *>(s);
      }
   return NULL;
   }
position_tolerance_without_referenced_datum_system *position_tolerance_without_referenced_datum_system::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<position_tolerance_without_referenced_datum_system *>(s);
      }
   return NULL;
   }
// construction factory
position_tolerance_without_referenced_datum_system *position_tolerance_without_referenced_datum_system::Construct() {
   position_tolerance_without_referenced_datum_system *result = NULL;

   // create the position_tolerance_without_referenced_datum_system.
   result = new position_tolerance_without_referenced_datum_system();
   return result;
   }
bool position_tolerance_without_referenced_datum_system::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: position_tolerance_without_referenced_datum_system\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (position_tolerance::hasRequiredAttributes() == false) {
      result = false;
      }
   if (geometric_tolerance_without_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
