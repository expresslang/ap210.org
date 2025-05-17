// Source for AP210 application object
//     positional_boundary_member_definition

// Precompiled include files
#include <StdAfx.h>

#include "positional_boundary_member_definition.h"

// Classes
#include <positional_boundary_member.h>
#include <length_data_element.h>
#include <dimensional_size.h>

positional_boundary_member_definition::positional_boundary_member_definition() {
   initialize();
   }
positional_boundary_member_definition::~positional_boundary_member_definition() {
   // Free string attributes
   }
// intialize data members
void positional_boundary_member_definition::initialize() {
   // Required attributes
   _defined_positional_boundary_member = NULL;
   _tolerance_value = NULL;
   _associated_dimension = NULL;

   // Optional attributes
   }
// Runtime type identification
int positional_boundary_member_definition::DynamicType(int ID) {
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
positional_boundary_member_definition *positional_boundary_member_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<positional_boundary_member_definition *>(s);
      }
   return NULL;
   }
positional_boundary_member_definition *positional_boundary_member_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<positional_boundary_member_definition *>(s);
      }
   return NULL;
   }
// construction factory
positional_boundary_member_definition *positional_boundary_member_definition::Construct() {
   positional_boundary_member_definition *result = NULL;

   // create the positional_boundary_member_definition.
   result = new positional_boundary_member_definition();
   return result;
   }
bool positional_boundary_member_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: positional_boundary_member_definition\r\n");

   // Check for the existence of all required attributes
   if (_defined_positional_boundary_member == NULL) {
      TRACE("ERROR: _defined_positional_boundary_member a required attribute is NULL!\r\n");
      result = false;
      }
   if (_tolerance_value == NULL) {
      TRACE("ERROR: _tolerance_value a required attribute is NULL!\r\n");
      result = false;
      }
   if (_associated_dimension == NULL) {
      TRACE("ERROR: _associated_dimension a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
