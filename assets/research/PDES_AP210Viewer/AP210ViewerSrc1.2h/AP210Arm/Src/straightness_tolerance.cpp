// Source for AP210 application object
//     straightness_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "straightness_tolerance.h"

// Classes

straightness_tolerance::straightness_tolerance() {
   initialize();
   }
straightness_tolerance::~straightness_tolerance() {
   // Free string attributes
   }
// intialize data members
void straightness_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int straightness_tolerance::DynamicType(int ID) {
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
straightness_tolerance *straightness_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<straightness_tolerance *>(s);
      }
   return NULL;
   }
straightness_tolerance *straightness_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<straightness_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
straightness_tolerance *straightness_tolerance::Construct() {
   straightness_tolerance *result = NULL;

   // create the straightness_tolerance.
   result = new straightness_tolerance();
   return result;
   }
bool straightness_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: straightness_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_without_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
