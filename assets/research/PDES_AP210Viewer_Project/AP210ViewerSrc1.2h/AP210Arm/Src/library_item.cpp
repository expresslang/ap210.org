// Source for AP210 application object
//     library_item

// Precompiled include files
#include <StdAfx.h>

#include "library_item.h"

// Classes

library_item::library_item() {
   initialize();
   }
library_item::~library_item() {
   // Free string attributes
   if (_item_version != NULL) {
      free(_item_version);
     }
   if (_library != NULL) {
      free(_library);
     }
   if (_item_name != NULL) {
      free(_item_name);
     }
   }
// intialize data members
void library_item::initialize() {
   // Required attributes
   _library = NULL;

   // Optional attributes
   _item_version = NULL;
   _item_name = NULL;
   }
// Runtime type identification
int library_item::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
library_item *library_item::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<library_item *>(s);
      }
   return NULL;
   }
library_item *library_item::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<library_item *>(s);
      }
   return NULL;
   }
// construction factory
library_item *library_item::Construct() {
   library_item *result = NULL;

   // create the library_item.
   result = new library_item();
   return result;
   }
bool library_item::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: library_item\r\n");

   // Check for the existence of all required attributes
   if (_library == NULL) {
      TRACE("ERROR: _library a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
