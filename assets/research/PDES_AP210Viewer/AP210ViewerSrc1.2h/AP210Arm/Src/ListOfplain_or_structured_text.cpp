// Source for AP210 application object
//     ListOfplain_or_structured_text

// Precompiled include files
#include <StdAfx.h>

#include "ListOfplain_or_structured_text.h"

// Classes

ListOfplain_or_structured_text::ListOfplain_or_structured_text() {
   initialize();
   }
ListOfplain_or_structured_text::~ListOfplain_or_structured_text() {
   // Free string attributes
   }
// intialize data members
void ListOfplain_or_structured_text::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int ListOfplain_or_structured_text::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
ListOfplain_or_structured_text *ListOfplain_or_structured_text::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ListOfplain_or_structured_text *>(s);
      }
   return NULL;
   }
ListOfplain_or_structured_text *ListOfplain_or_structured_text::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ListOfplain_or_structured_text *>(s);
      }
   return NULL;
   }
// construction factory
ListOfplain_or_structured_text *ListOfplain_or_structured_text::Construct() {
   ListOfplain_or_structured_text *result = NULL;

   // create the ListOfplain_or_structured_text.
   result = new ListOfplain_or_structured_text();
   return result;
   }
bool ListOfplain_or_structured_text::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ListOfplain_or_structured_text\r\n");

   // Check for the existence of all required attributes
   if (_plain_or_structured_text == NULL) {
      TRACE("ERROR: _plain_or_structured_text a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
