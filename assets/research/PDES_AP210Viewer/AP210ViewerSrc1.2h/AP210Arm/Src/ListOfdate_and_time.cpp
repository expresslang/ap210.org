// Source for AP210 application object
//     ListOfdate_and_time

// Precompiled include files
#include <StdAfx.h>

#include "ListOfdate_and_time.h"

// Classes
#include <date_and_time.h>

ListOfdate_and_time::ListOfdate_and_time() {
   initialize();
   }
ListOfdate_and_time::~ListOfdate_and_time() {
   // Free string attributes
   }
// intialize data members
void ListOfdate_and_time::initialize() {
   // Required attributes
   _date_and_time = NULL;

   // Optional attributes
   }
// Runtime type identification
int ListOfdate_and_time::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
ListOfdate_and_time *ListOfdate_and_time::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ListOfdate_and_time *>(s);
      }
   return NULL;
   }
ListOfdate_and_time *ListOfdate_and_time::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ListOfdate_and_time *>(s);
      }
   return NULL;
   }
// construction factory
ListOfdate_and_time *ListOfdate_and_time::Construct() {
   ListOfdate_and_time *result = NULL;

   // create the ListOfdate_and_time.
   result = new ListOfdate_and_time();
   return result;
   }
bool ListOfdate_and_time::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ListOfdate_and_time\r\n");

   // Check for the existence of all required attributes
   if (_date_and_time == NULL) {
      TRACE("ERROR: _date_and_time a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
