// Source for AP210 application object
//     datum_target_set

// Precompiled include files
#include <StdAfx.h>

#include "datum_target_set.h"

// Classes

datum_target_set::datum_target_set() {
   initialize();
   }
datum_target_set::~datum_target_set() {
   // Free string attributes
   }
// intialize data members
void datum_target_set::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int datum_target_set::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = datum_feature::DynamicType(ID);
      }
   return result;
   }
datum_target_set *datum_target_set::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_target_set *>(s);
      }
   return NULL;
   }
datum_target_set *datum_target_set::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_target_set *>(s);
      }
   return NULL;
   }
// construction factory
datum_target_set *datum_target_set::Construct() {
   datum_target_set *result = NULL;

   // create the datum_target_set.
   result = new datum_target_set();
   return result;
   }
bool datum_target_set::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_target_set\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (datum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
