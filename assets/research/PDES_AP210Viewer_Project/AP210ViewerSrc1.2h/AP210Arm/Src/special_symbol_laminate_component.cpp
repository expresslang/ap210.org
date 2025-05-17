// Source for AP210 application object
//     special_symbol_laminate_component

// Precompiled include files
#include <StdAfx.h>

#include "special_symbol_laminate_component.h"

// Classes
#include <stratum_feature.h>

special_symbol_laminate_component::special_symbol_laminate_component() {
   initialize();
   }
special_symbol_laminate_component::~special_symbol_laminate_component() {
   // Free string attributes
   }
// intialize data members
void special_symbol_laminate_component::initialize() {
   // Required attributes
   _stratum_feature_implementation = NULL;

   // Optional attributes
   }
// Runtime type identification
int special_symbol_laminate_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = laminate_component::DynamicType(ID);
      }
   return result;
   }
special_symbol_laminate_component *special_symbol_laminate_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<special_symbol_laminate_component *>(s);
      }
   return NULL;
   }
special_symbol_laminate_component *special_symbol_laminate_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<special_symbol_laminate_component *>(s);
      }
   return NULL;
   }
// construction factory
special_symbol_laminate_component *special_symbol_laminate_component::Construct() {
   special_symbol_laminate_component *result = NULL;

   // create the special_symbol_laminate_component.
   result = new special_symbol_laminate_component();
   return result;
   }
bool special_symbol_laminate_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: special_symbol_laminate_component\r\n");

   // Check for the existence of all required attributes
   if (_stratum_feature_implementation == NULL) {
      TRACE("ERROR: _stratum_feature_implementation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
