// Source for AP210 application object
//     language_reference_manual

// Precompiled include files
#include <StdAfx.h>

#include "language_reference_manual.h"

// Classes

language_reference_manual::language_reference_manual() {
   initialize();
   }
language_reference_manual::~language_reference_manual() {
   // Free string attributes
   }
// intialize data members
void language_reference_manual::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int language_reference_manual::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_specification::DynamicType(ID);
      }
   return result;
   }
language_reference_manual *language_reference_manual::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<language_reference_manual *>(s);
      }
   return NULL;
   }
language_reference_manual *language_reference_manual::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<language_reference_manual *>(s);
      }
   return NULL;
   }
// construction factory
language_reference_manual *language_reference_manual::Construct() {
   language_reference_manual *result = NULL;

   // create the language_reference_manual.
   result = new language_reference_manual();
   return result;
   }
bool language_reference_manual::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: language_reference_manual\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (ee_specification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
