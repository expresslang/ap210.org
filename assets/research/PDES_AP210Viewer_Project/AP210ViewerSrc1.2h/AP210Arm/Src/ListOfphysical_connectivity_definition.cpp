// Source for AP210 application object
//     ListOfphysical_connectivity_definition

// Precompiled include files
#include <StdAfx.h>

#include "ListOfphysical_connectivity_definition.h"

// Classes
#include <physical_connectivity_definition.h>

ListOfphysical_connectivity_definition::ListOfphysical_connectivity_definition() {
   initialize();
   }
ListOfphysical_connectivity_definition::~ListOfphysical_connectivity_definition() {
   // Free string attributes
   }
// intialize data members
void ListOfphysical_connectivity_definition::initialize() {
   // Required attributes
   _physical_connectivity_definition = NULL;

   // Optional attributes
   }
// Runtime type identification
int ListOfphysical_connectivity_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
ListOfphysical_connectivity_definition *ListOfphysical_connectivity_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ListOfphysical_connectivity_definition *>(s);
      }
   return NULL;
   }
ListOfphysical_connectivity_definition *ListOfphysical_connectivity_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ListOfphysical_connectivity_definition *>(s);
      }
   return NULL;
   }
// construction factory
ListOfphysical_connectivity_definition *ListOfphysical_connectivity_definition::Construct() {
   ListOfphysical_connectivity_definition *result = NULL;

   // create the ListOfphysical_connectivity_definition.
   result = new ListOfphysical_connectivity_definition();
   return result;
   }
bool ListOfphysical_connectivity_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ListOfphysical_connectivity_definition\r\n");

   // Check for the existence of all required attributes
   if (_physical_connectivity_definition == NULL) {
      TRACE("ERROR: _physical_connectivity_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
