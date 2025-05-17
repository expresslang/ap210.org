// Source for AP210 application object
//     ListOfprinted_part_template_material

// Precompiled include files
#include <StdAfx.h>

#include "ListOfprinted_part_template_material.h"

// Classes
#include <printed_part_template_material.h>

ListOfprinted_part_template_material::ListOfprinted_part_template_material() {
   initialize();
   }
ListOfprinted_part_template_material::~ListOfprinted_part_template_material() {
   // Free string attributes
   }
// intialize data members
void ListOfprinted_part_template_material::initialize() {
   // Required attributes
   _printed_part_template_material = NULL;

   // Optional attributes
   }
// Runtime type identification
int ListOfprinted_part_template_material::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
ListOfprinted_part_template_material *ListOfprinted_part_template_material::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ListOfprinted_part_template_material *>(s);
      }
   return NULL;
   }
ListOfprinted_part_template_material *ListOfprinted_part_template_material::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ListOfprinted_part_template_material *>(s);
      }
   return NULL;
   }
// construction factory
ListOfprinted_part_template_material *ListOfprinted_part_template_material::Construct() {
   ListOfprinted_part_template_material *result = NULL;

   // create the ListOfprinted_part_template_material.
   result = new ListOfprinted_part_template_material();
   return result;
   }
bool ListOfprinted_part_template_material::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ListOfprinted_part_template_material\r\n");

   // Check for the existence of all required attributes
   if (_printed_part_template_material == NULL) {
      TRACE("ERROR: _printed_part_template_material a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
