// Source for AP210 application object
//     position_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "position_tolerance.h"

// Classes

position_tolerance::position_tolerance() {
   initialize();
   }
position_tolerance::~position_tolerance() {
   // Free string attributes
   }
// intialize data members
void position_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int position_tolerance::DynamicType(int ID) {
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
position_tolerance *position_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<position_tolerance *>(s);
      }
   return NULL;
   }
position_tolerance *position_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<position_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
position_tolerance *position_tolerance::Construct() {
   position_tolerance *result = NULL;

   // create the position_tolerance.
   result = new position_tolerance();
   return result;
   }
bool position_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: position_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
