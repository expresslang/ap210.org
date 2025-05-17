// Source for AP210 application object
//     SetOfshieldable_item

// Precompiled include files
#include <StdAfx.h>

#include "SetOfshieldable_item.h"

// Classes

SetOfshieldable_item::SetOfshieldable_item() {
   initialize();
   }
SetOfshieldable_item::~SetOfshieldable_item() {
   // Free string attributes
   }
// intialize data members
void SetOfshieldable_item::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOfshieldable_item::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfshieldable_item *SetOfshieldable_item::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfshieldable_item *>(s);
      }
   return NULL;
   }
SetOfshieldable_item *SetOfshieldable_item::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfshieldable_item *>(s);
      }
   return NULL;
   }
// construction factory
SetOfshieldable_item *SetOfshieldable_item::Construct() {
   SetOfshieldable_item *result = NULL;

   // create the SetOfshieldable_item.
   result = new SetOfshieldable_item();
   return result;
   }
bool SetOfshieldable_item::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfshieldable_item\r\n");

   // Check for the existence of all required attributes
   if (_shieldable_item == NULL) {
      TRACE("ERROR: _shieldable_item a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
