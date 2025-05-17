// Source for AP210 application object
//     item_restricted_requirement_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "item_restricted_requirement_occurrence.h"

// Classes

item_restricted_requirement_occurrence::item_restricted_requirement_occurrence() {
   initialize();
   }
item_restricted_requirement_occurrence::~item_restricted_requirement_occurrence() {
   // Free string attributes
   }
// intialize data members
void item_restricted_requirement_occurrence::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int item_restricted_requirement_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = ee_requirement_occurrence::DynamicType(ID);
      }
   return result;
   }
item_restricted_requirement_occurrence *item_restricted_requirement_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<item_restricted_requirement_occurrence *>(s);
      }
   return NULL;
   }
item_restricted_requirement_occurrence *item_restricted_requirement_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<item_restricted_requirement_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
item_restricted_requirement_occurrence *item_restricted_requirement_occurrence::Construct() {
   item_restricted_requirement_occurrence *result = NULL;

   // create the item_restricted_requirement_occurrence.
   result = new item_restricted_requirement_occurrence();
   return result;
   }
bool item_restricted_requirement_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: item_restricted_requirement_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_basis == NULL) {
      TRACE("ERROR: _basis a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (ee_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
