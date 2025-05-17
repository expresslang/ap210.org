// Source for AP210 application object
//     date

// Precompiled include files
#include <StdAfx.h>

#include "date.h"

// Classes

date::date() {
   initialize();
   }
date::~date() {
   // Free string attributes
   }
// intialize data members
void date::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int date::DynamicType(int ID) {
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
date *date::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<date *>(s);
      }
   return NULL;
   }
date *date::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<date *>(s);
      }
   return NULL;
   }
// construction factory
date *date::Construct() {
   date *result = NULL;

   // create the date.
   result = new date();
   return result;
   }
bool date::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: date\r\n");

   // Check for the existence of all required attributes
   if (_day == NULL) {
      TRACE("ERROR: _day a required attribute is NULL!\r\n");
      result = false;
      }
   if (_year == NULL) {
      TRACE("ERROR: _year a required attribute is NULL!\r\n");
      result = false;
      }
   if (_month == NULL) {
      TRACE("ERROR: _month a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
