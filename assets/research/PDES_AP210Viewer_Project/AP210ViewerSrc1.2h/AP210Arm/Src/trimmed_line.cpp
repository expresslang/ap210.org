// Source for AP210 application object
//     trimmed_line

// Precompiled include files
#include <StdAfx.h>

#include "trimmed_line.h"

// Classes

trimmed_line::trimmed_line() {
   initialize();
   }
trimmed_line::~trimmed_line() {
   // Free string attributes
   }
// intialize data members
void trimmed_line::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int trimmed_line::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = curve::DynamicType(ID);
      }
   return result;
   }
trimmed_line *trimmed_line::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<trimmed_line *>(s);
      }
   return NULL;
   }
trimmed_line *trimmed_line::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<trimmed_line *>(s);
      }
   return NULL;
   }
// construction factory
trimmed_line *trimmed_line::Construct() {
   trimmed_line *result = NULL;

   // create the trimmed_line.
   result = new trimmed_line();
   return result;
   }
bool trimmed_line::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: trimmed_line\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (curve::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
