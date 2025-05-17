// Source for AP210 application object
//     datum_point

// Precompiled include files
#include <StdAfx.h>

#include "datum_point.h"

// Classes

datum_point::datum_point() {
   initialize();
   }
datum_point::~datum_point() {
   // Free string attributes
   }
// intialize data members
void datum_point::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int datum_point::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = datum::DynamicType(ID);
      }
   return result;
   }
datum_point *datum_point::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_point *>(s);
      }
   return NULL;
   }
datum_point *datum_point::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_point *>(s);
      }
   return NULL;
   }
// construction factory
datum_point *datum_point::Construct() {
   datum_point *result = NULL;

   // create the datum_point.
   result = new datum_point();
   return result;
   }
bool datum_point::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_point\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (datum::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
