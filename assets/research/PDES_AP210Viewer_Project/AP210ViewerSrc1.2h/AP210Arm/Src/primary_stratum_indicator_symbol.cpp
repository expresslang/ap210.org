// Source for AP210 application object
//     primary_stratum_indicator_symbol

// Precompiled include files
#include <StdAfx.h>

#include "primary_stratum_indicator_symbol.h"

// Classes

primary_stratum_indicator_symbol::primary_stratum_indicator_symbol() {
   initialize();
   }
primary_stratum_indicator_symbol::~primary_stratum_indicator_symbol() {
   // Free string attributes
   }
// intialize data members
void primary_stratum_indicator_symbol::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int primary_stratum_indicator_symbol::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = special_symbol_laminate_component::DynamicType(ID);
      }
   return result;
   }
primary_stratum_indicator_symbol *primary_stratum_indicator_symbol::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<primary_stratum_indicator_symbol *>(s);
      }
   return NULL;
   }
primary_stratum_indicator_symbol *primary_stratum_indicator_symbol::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<primary_stratum_indicator_symbol *>(s);
      }
   return NULL;
   }
// construction factory
primary_stratum_indicator_symbol *primary_stratum_indicator_symbol::Construct() {
   primary_stratum_indicator_symbol *result = NULL;

   // create the primary_stratum_indicator_symbol.
   result = new primary_stratum_indicator_symbol();
   return result;
   }
bool primary_stratum_indicator_symbol::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: primary_stratum_indicator_symbol\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (special_symbol_laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
