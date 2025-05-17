// Source for AP210 application object
//     SetOffill_area_style

// Precompiled include files
#include <StdAfx.h>

#include "SetOffill_area_style.h"

// Classes
#include <fill_area_style.h>

SetOffill_area_style::SetOffill_area_style() {
   initialize();
   }
SetOffill_area_style::~SetOffill_area_style() {
   // Free string attributes
   }
// intialize data members
void SetOffill_area_style::initialize() {
   // Required attributes
   _fill_area_style = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOffill_area_style::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOffill_area_style *SetOffill_area_style::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOffill_area_style *>(s);
      }
   return NULL;
   }
SetOffill_area_style *SetOffill_area_style::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOffill_area_style *>(s);
      }
   return NULL;
   }
// construction factory
SetOffill_area_style *SetOffill_area_style::Construct() {
   SetOffill_area_style *result = NULL;

   // create the SetOffill_area_style.
   result = new SetOffill_area_style();
   return result;
   }
bool SetOffill_area_style::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOffill_area_style\r\n");

   // Check for the existence of all required attributes
   if (_fill_area_style == NULL) {
      TRACE("ERROR: _fill_area_style a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
