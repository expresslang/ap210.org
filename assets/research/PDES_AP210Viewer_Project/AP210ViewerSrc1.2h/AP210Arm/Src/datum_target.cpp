// Source for AP210 application object
//     datum_target

// Precompiled include files
#include <StdAfx.h>

#include "datum_target.h"

// Classes

datum_target::datum_target() {
   initialize();
   }
datum_target::~datum_target() {
   // Free string attributes
   }
// intialize data members
void datum_target::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int datum_target::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = physical_feature_or_part_template::DynamicType(ID);
      }
   return result;
   }
datum_target *datum_target::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_target *>(s);
      }
   return NULL;
   }
datum_target *datum_target::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_target *>(s);
      }
   return NULL;
   }
// construction factory
datum_target *datum_target::Construct() {
   datum_target *result = NULL;

   // create the datum_target.
   result = new datum_target();
   return result;
   }
bool datum_target::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_target\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (physical_feature_or_part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
