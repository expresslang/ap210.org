// Source for AP210 application object
//     planned_serial_number_effectivity

// Precompiled include files
#include <StdAfx.h>

#include "planned_serial_number_effectivity.h"

// Classes

planned_serial_number_effectivity::planned_serial_number_effectivity() {
   initialize();
   }
planned_serial_number_effectivity::~planned_serial_number_effectivity() {
   // Free string attributes
   if (_through_effectivity_id != NULL) {
      free(_through_effectivity_id);
     }
   if (_from_effectivity_id != NULL) {
      free(_from_effectivity_id);
     }
   }
// intialize data members
void planned_serial_number_effectivity::initialize() {
   // Required attributes
   _from_effectivity_id = NULL;

   // Optional attributes
   _through_effectivity_id = NULL;
   }
// Runtime type identification
int planned_serial_number_effectivity::DynamicType(int ID) {
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
planned_serial_number_effectivity *planned_serial_number_effectivity::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<planned_serial_number_effectivity *>(s);
      }
   return NULL;
   }
planned_serial_number_effectivity *planned_serial_number_effectivity::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<planned_serial_number_effectivity *>(s);
      }
   return NULL;
   }
// construction factory
planned_serial_number_effectivity *planned_serial_number_effectivity::Construct() {
   planned_serial_number_effectivity *result = NULL;

   // create the planned_serial_number_effectivity.
   result = new planned_serial_number_effectivity();
   return result;
   }
bool planned_serial_number_effectivity::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: planned_serial_number_effectivity\r\n");

   // Check for the existence of all required attributes
   if (_from_effectivity_id == NULL) {
      TRACE("ERROR: _from_effectivity_id a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (planned_effectivity::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
