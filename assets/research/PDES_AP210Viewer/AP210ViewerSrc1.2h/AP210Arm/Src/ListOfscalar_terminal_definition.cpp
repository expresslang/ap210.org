// Source for AP210 application object
//     ListOfscalar_terminal_definition

// Precompiled include files
#include <StdAfx.h>

#include "ListOfscalar_terminal_definition.h"

// Classes
#include <scalar_terminal_definition.h>

ListOfscalar_terminal_definition::ListOfscalar_terminal_definition() {
   initialize();
   }
ListOfscalar_terminal_definition::~ListOfscalar_terminal_definition() {
   // Free string attributes
   }
// intialize data members
void ListOfscalar_terminal_definition::initialize() {
   // Required attributes
   _scalar_terminal_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int ListOfscalar_terminal_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
ListOfscalar_terminal_definition *ListOfscalar_terminal_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ListOfscalar_terminal_definition *>(s);
      }
   return NULL;
   }
ListOfscalar_terminal_definition *ListOfscalar_terminal_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ListOfscalar_terminal_definition *>(s);
      }
   return NULL;
   }
// construction factory
ListOfscalar_terminal_definition *ListOfscalar_terminal_definition::Construct() {
   ListOfscalar_terminal_definition *result = NULL;

   // create the ListOfscalar_terminal_definition.
   result = new ListOfscalar_terminal_definition();
   return result;
   }
bool ListOfscalar_terminal_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ListOfscalar_terminal_definition\r\n");

   // Check for the existence of all required attributes
   if (_scalar_terminal_definition == NULL) {
      TRACE("ERROR: _scalar_terminal_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
