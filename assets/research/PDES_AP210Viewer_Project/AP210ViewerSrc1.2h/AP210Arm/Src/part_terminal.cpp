// Source for AP210 application object
//     part_terminal

// Precompiled include files
#include <StdAfx.h>

#include "part_terminal.h"

// Classes

part_terminal::part_terminal() {
   initialize();
   }
part_terminal::~part_terminal() {
   // Free string attributes
   }
// intialize data members
void part_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int part_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_feature::DynamicType(ID);
      }
   return result;
   }
part_terminal *part_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_terminal *>(s);
      }
   return NULL;
   }
part_terminal *part_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_terminal *>(s);
      }
   return NULL;
   }
// construction factory
part_terminal *part_terminal::Construct() {
   part_terminal *result = NULL;

   // create the part_terminal.
   result = new part_terminal();
   return result;
   }
bool part_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (part_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
