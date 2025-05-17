// Source for AP210 application object
//     datum_difference_functional_unit_usage_view_terminal_assignment

// Precompiled include files
#include <StdAfx.h>

#include "datum_difference_functional_unit_usage_view_terminal_assignment.h"

// Classes
#include <functional_unit_usage_view_terminal_definition.h>
#include <datum_difference.h>

datum_difference_functional_unit_usage_view_terminal_assignment::datum_difference_functional_unit_usage_view_terminal_assignment() {
   initialize();
   }
datum_difference_functional_unit_usage_view_terminal_assignment::~datum_difference_functional_unit_usage_view_terminal_assignment() {
   // Free string attributes
   }
// intialize data members
void datum_difference_functional_unit_usage_view_terminal_assignment::initialize() {
   // Required attributes
   _assigned_functional_terminal_definition = NULL;
   _assigned_datum_difference = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_difference_functional_unit_usage_view_terminal_assignment::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = managed_design_object::DynamicType(ID);
      }
   return result;
   }
datum_difference_functional_unit_usage_view_terminal_assignment *datum_difference_functional_unit_usage_view_terminal_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_difference_functional_unit_usage_view_terminal_assignment *>(s);
      }
   return NULL;
   }
datum_difference_functional_unit_usage_view_terminal_assignment *datum_difference_functional_unit_usage_view_terminal_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_difference_functional_unit_usage_view_terminal_assignment *>(s);
      }
   return NULL;
   }
// construction factory
datum_difference_functional_unit_usage_view_terminal_assignment *datum_difference_functional_unit_usage_view_terminal_assignment::Construct() {
   datum_difference_functional_unit_usage_view_terminal_assignment *result = NULL;

   // create the datum_difference_functional_unit_usage_view_terminal_assignment.
   result = new datum_difference_functional_unit_usage_view_terminal_assignment();
   return result;
   }
bool datum_difference_functional_unit_usage_view_terminal_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_difference_functional_unit_usage_view_terminal_assignment\r\n");

   // Check for the existence of all required attributes
   if (_assigned_functional_terminal_definition == NULL) {
      TRACE("ERROR: _assigned_functional_terminal_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_datum_difference == NULL) {
      TRACE("ERROR: _assigned_datum_difference a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
