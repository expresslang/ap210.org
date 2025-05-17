// Source for AP210 application object
//     change_order

// Precompiled include files
#include <StdAfx.h>

#include "change_order.h"

// Classes

change_order::change_order() {
   initialize();
   }
change_order::~change_order() {
   // Free string attributes
   }
// intialize data members
void change_order::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int change_order::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = work_order::DynamicType(ID);
      }
   return result;
   }
change_order *change_order::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<change_order *>(s);
      }
   return NULL;
   }
change_order *change_order::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<change_order *>(s);
      }
   return NULL;
   }
// construction factory
change_order *change_order::Construct() {
   change_order *result = NULL;

   // create the change_order.
   result = new change_order();
   return result;
   }
bool change_order::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: change_order\r\n");

   // Check for the existence of all required attributes
   if (_adopted_solution == NULL) {
      TRACE("ERROR: _adopted_solution a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (work_order::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
