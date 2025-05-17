// Source for AP210 application object
//     planned_date_effectivity

// Precompiled include files
#include <StdAfx.h>

#include "planned_date_effectivity.h"

// Classes

planned_date_effectivity::planned_date_effectivity() {
   initialize();
   }
planned_date_effectivity::~planned_date_effectivity() {
   // Free string attributes
   }
// intialize data members
void planned_date_effectivity::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int planned_date_effectivity::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = planned_effectivity::DynamicType(ID);
      }
   return result;
   }
planned_date_effectivity *planned_date_effectivity::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<planned_date_effectivity *>(s);
      }
   return NULL;
   }
planned_date_effectivity *planned_date_effectivity::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<planned_date_effectivity *>(s);
      }
   return NULL;
   }
// construction factory
planned_date_effectivity *planned_date_effectivity::Construct() {
   planned_date_effectivity *result = NULL;

   // create the planned_date_effectivity.
   result = new planned_date_effectivity();
   return result;
   }
bool planned_date_effectivity::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: planned_date_effectivity\r\n");

   // Check for the existence of all required attributes
   if (_start_date == NULL) {
      TRACE("ERROR: _start_date a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (planned_effectivity::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
