// Source for AP210 application object
//     datum_difference

// Precompiled include files
#include <StdAfx.h>

#include "datum_difference.h"

// Classes

datum_difference::datum_difference() {
   initialize();
   }
datum_difference::~datum_difference() {
   // Free string attributes
   }
// intialize data members
void datum_difference::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int datum_difference::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = shape_element_relationship::DynamicType(ID);
      }
   return result;
   }
datum_difference *datum_difference::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_difference *>(s);
      }
   return NULL;
   }
datum_difference *datum_difference::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_difference *>(s);
      }
   return NULL;
   }
// construction factory
datum_difference *datum_difference::Construct() {
   datum_difference *result = NULL;

   // create the datum_difference.
   result = new datum_difference();
   return result;
   }
bool datum_difference::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_difference\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (shape_element_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
