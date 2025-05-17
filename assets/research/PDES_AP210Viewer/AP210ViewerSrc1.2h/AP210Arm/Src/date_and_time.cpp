// Source for AP210 application object
//     date_and_time

// Precompiled include files
#include <StdAfx.h>

#include "date_and_time.h"

// Classes

date_and_time::date_and_time() {
   initialize();
   }
date_and_time::~date_and_time() {
   // Free string attributes
   }
// intialize data members
void date_and_time::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int date_and_time::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = date::DynamicType(ID);
      }
   return result;
   }
date_and_time *date_and_time::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<date_and_time *>(s);
      }
   return NULL;
   }
date_and_time *date_and_time::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<date_and_time *>(s);
      }
   return NULL;
   }
// construction factory
date_and_time *date_and_time::Construct() {
   date_and_time *result = NULL;

   // create the date_and_time.
   result = new date_and_time();
   return result;
   }
bool date_and_time::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: date_and_time\r\n");

   // Check for the existence of all required attributes
   if (_hour == NULL) {
      TRACE("ERROR: _hour a required attribute is NULL!\r\n");
      result = false;
      }
   if (_minute == NULL) {
      TRACE("ERROR: _minute a required attribute is NULL!\r\n");
      result = false;
      }
   if (_second == NULL) {
      TRACE("ERROR: _second a required attribute is NULL!\r\n");
      result = false;
      }
   if (_time_zone == NULL) {
      TRACE("ERROR: _time_zone a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (date::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
