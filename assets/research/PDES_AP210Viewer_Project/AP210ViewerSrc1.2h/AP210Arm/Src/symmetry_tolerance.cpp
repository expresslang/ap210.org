// Source for AP210 application object
//     symmetry_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "symmetry_tolerance.h"

// Classes

symmetry_tolerance::symmetry_tolerance() {
   initialize();
   }
symmetry_tolerance::~symmetry_tolerance() {
   // Free string attributes
   }
// intialize data members
void symmetry_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int symmetry_tolerance::DynamicType(int ID) {
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
symmetry_tolerance *symmetry_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<symmetry_tolerance *>(s);
      }
   return NULL;
   }
symmetry_tolerance *symmetry_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<symmetry_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
symmetry_tolerance *symmetry_tolerance::Construct() {
   symmetry_tolerance *result = NULL;

   // create the symmetry_tolerance.
   result = new symmetry_tolerance();
   return result;
   }
bool symmetry_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: symmetry_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_with_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
