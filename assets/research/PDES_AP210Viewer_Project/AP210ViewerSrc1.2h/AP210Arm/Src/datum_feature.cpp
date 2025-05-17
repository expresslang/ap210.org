// Source for AP210 application object
//     datum_feature

// Precompiled include files
#include <StdAfx.h>

#include "datum_feature.h"

// Classes

datum_feature::datum_feature() {
   initialize();
   }
datum_feature::~datum_feature() {
   // Free string attributes
   if (_identification != NULL) {
      free(_identification);
     }
   }
// intialize data members
void datum_feature::initialize() {
   // Required attributes
   _identification = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_feature::DynamicType(int ID) {
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
datum_feature *datum_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_feature *>(s);
      }
   return NULL;
   }
datum_feature *datum_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_feature *>(s);
      }
   return NULL;
   }
// construction factory
datum_feature *datum_feature::Construct() {
   datum_feature *result = NULL;

   // create the datum_feature.
   result = new datum_feature();
   return result;
   }
bool datum_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_feature\r\n");

   // Check for the existence of all required attributes
   if (_identification == NULL) {
      TRACE("ERROR: _identification a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (physical_feature_or_part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
