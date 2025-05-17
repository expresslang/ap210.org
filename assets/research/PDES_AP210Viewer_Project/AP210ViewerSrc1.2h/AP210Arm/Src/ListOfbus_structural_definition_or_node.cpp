// Source for AP210 application object
//     ListOfbus_structural_definition_or_node

// Precompiled include files
#include <StdAfx.h>

#include "ListOfbus_structural_definition_or_node.h"

// Classes

ListOfbus_structural_definition_or_node::ListOfbus_structural_definition_or_node() {
   initialize();
   }
ListOfbus_structural_definition_or_node::~ListOfbus_structural_definition_or_node() {
   // Free string attributes
   }
// intialize data members
void ListOfbus_structural_definition_or_node::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int ListOfbus_structural_definition_or_node::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
ListOfbus_structural_definition_or_node *ListOfbus_structural_definition_or_node::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ListOfbus_structural_definition_or_node *>(s);
      }
   return NULL;
   }
ListOfbus_structural_definition_or_node *ListOfbus_structural_definition_or_node::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ListOfbus_structural_definition_or_node *>(s);
      }
   return NULL;
   }
// construction factory
ListOfbus_structural_definition_or_node *ListOfbus_structural_definition_or_node::Construct() {
   ListOfbus_structural_definition_or_node *result = NULL;

   // create the ListOfbus_structural_definition_or_node.
   result = new ListOfbus_structural_definition_or_node();
   return result;
   }
bool ListOfbus_structural_definition_or_node::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ListOfbus_structural_definition_or_node\r\n");

   // Check for the existence of all required attributes
   if (_bus_structural_definition_or_node == NULL) {
      TRACE("ERROR: _bus_structural_definition_or_node a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
