// Source for AP210 application object
//     circularity_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "circularity_tolerance.h"

// Classes

circularity_tolerance::circularity_tolerance() {
   initialize();
   }
circularity_tolerance::~circularity_tolerance() {
   // Free string attributes
   }
// intialize data members
void circularity_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int circularity_tolerance::DynamicType(int ID) {
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
circularity_tolerance *circularity_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<circularity_tolerance *>(s);
      }
   return NULL;
   }
circularity_tolerance *circularity_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<circularity_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
circularity_tolerance *circularity_tolerance::Construct() {
   circularity_tolerance *result = NULL;

   // create the circularity_tolerance.
   result = new circularity_tolerance();
   return result;
   }
bool circularity_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: circularity_tolerance\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_without_referenced_datum_system::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
