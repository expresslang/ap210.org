// Source for AP210 application object
//     special_symbol_part_template

// Precompiled include files
#include <StdAfx.h>

#include "special_symbol_part_template.h"

// Classes

special_symbol_part_template::special_symbol_part_template() {
   initialize();
   }
special_symbol_part_template::~special_symbol_part_template() {
   // Free string attributes
   }
// intialize data members
void special_symbol_part_template::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int special_symbol_part_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_template::DynamicType(ID);
      }
   return result;
   }
special_symbol_part_template *special_symbol_part_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<special_symbol_part_template *>(s);
      }
   return NULL;
   }
special_symbol_part_template *special_symbol_part_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<special_symbol_part_template *>(s);
      }
   return NULL;
   }
// construction factory
special_symbol_part_template *special_symbol_part_template::Construct() {
   special_symbol_part_template *result = NULL;

   // create the special_symbol_part_template.
   result = new special_symbol_part_template();
   return result;
   }
bool special_symbol_part_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: special_symbol_part_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
