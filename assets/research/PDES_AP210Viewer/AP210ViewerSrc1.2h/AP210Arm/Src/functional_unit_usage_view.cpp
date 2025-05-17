// Source for AP210 application object
//     functional_unit_usage_view

// Precompiled include files
#include <StdAfx.h>

#include "functional_unit_usage_view.h"

// Classes

functional_unit_usage_view::functional_unit_usage_view() {
   initialize();
   }
functional_unit_usage_view::~functional_unit_usage_view() {
   // Free string attributes
   }
// intialize data members
void functional_unit_usage_view::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int functional_unit_usage_view::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = functional_unit_definition::DynamicType(ID);
      }
   return result;
   }
functional_unit_usage_view *functional_unit_usage_view::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<functional_unit_usage_view *>(s);
      }
   return NULL;
   }
functional_unit_usage_view *functional_unit_usage_view::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<functional_unit_usage_view *>(s);
      }
   return NULL;
   }
// construction factory
functional_unit_usage_view *functional_unit_usage_view::Construct() {
   functional_unit_usage_view *result = NULL;

   // create the functional_unit_usage_view.
   result = new functional_unit_usage_view();
   return result;
   }
bool functional_unit_usage_view::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: functional_unit_usage_view\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (functional_unit_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
