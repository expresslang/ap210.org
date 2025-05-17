// Source for AP210 application object
//     datum_axis

// Precompiled include files
#include <StdAfx.h>

#include "datum_axis.h"

// Classes

datum_axis::datum_axis() {
   initialize();
   }
datum_axis::~datum_axis() {
   // Free string attributes
   }
// intialize data members
void datum_axis::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int datum_axis::DynamicType(int ID) {
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
datum_axis *datum_axis::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_axis *>(s);
      }
   return NULL;
   }
datum_axis *datum_axis::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_axis *>(s);
      }
   return NULL;
   }
// construction factory
datum_axis *datum_axis::Construct() {
   datum_axis *result = NULL;

   // create the datum_axis.
   result = new datum_axis();
   return result;
   }
bool datum_axis::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_axis\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (datum::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
