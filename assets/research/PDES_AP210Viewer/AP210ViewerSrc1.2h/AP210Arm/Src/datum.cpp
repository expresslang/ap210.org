// Source for AP210 application object
//     datum

// Precompiled include files
#include <StdAfx.h>

#include "datum.h"

// Classes

datum::datum() {
   initialize();
   }
datum::~datum() {
   // Free string attributes
   }
// intialize data members
void datum::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int datum::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = non_feature_shape_element::DynamicType(ID);
      }
   return result;
   }
datum *datum::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum *>(s);
      }
   return NULL;
   }
datum *datum::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum *>(s);
      }
   return NULL;
   }
// construction factory
datum *datum::Construct() {
   datum *result = NULL;

   // create the datum.
   result = new datum();
   return result;
   }
bool datum::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (non_feature_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
