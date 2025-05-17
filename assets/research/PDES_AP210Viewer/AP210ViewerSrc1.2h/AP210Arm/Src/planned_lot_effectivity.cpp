// Source for AP210 application object
//     planned_lot_effectivity

// Precompiled include files
#include <StdAfx.h>

#include "planned_lot_effectivity.h"

// Classes
#include <data_element.h>

planned_lot_effectivity::planned_lot_effectivity() {
   initialize();
   }
planned_lot_effectivity::~planned_lot_effectivity() {
   // Free string attributes
   if (_lot_number != NULL) {
      free(_lot_number);
     }
   }
// intialize data members
void planned_lot_effectivity::initialize() {
   // Required attributes
   _lot_number = NULL;
   _lot_size = NULL;

   // Optional attributes
   }
// Runtime type identification
int planned_lot_effectivity::DynamicType(int ID) {
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
planned_lot_effectivity *planned_lot_effectivity::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<planned_lot_effectivity *>(s);
      }
   return NULL;
   }
planned_lot_effectivity *planned_lot_effectivity::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<planned_lot_effectivity *>(s);
      }
   return NULL;
   }
// construction factory
planned_lot_effectivity *planned_lot_effectivity::Construct() {
   planned_lot_effectivity *result = NULL;

   // create the planned_lot_effectivity.
   result = new planned_lot_effectivity();
   return result;
   }
bool planned_lot_effectivity::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: planned_lot_effectivity\r\n");

   // Check for the existence of all required attributes
   if (_lot_number == NULL) {
      TRACE("ERROR: _lot_number a required attribute is NULL!\r\n");
      result = false;
      }
   if (_lot_size == NULL) {
      TRACE("ERROR: _lot_size a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (planned_effectivity::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
