// Source for AP210 application object
//     boolean_csg_result

// Precompiled include files
#include <StdAfx.h>

#include "boolean_csg_result.h"

// Classes

boolean_csg_result::boolean_csg_result() {
   initialize();
   }
boolean_csg_result::~boolean_csg_result() {
   // Free string attributes
   }
// intialize data members
void boolean_csg_result::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int boolean_csg_result::DynamicType(int ID) {
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
boolean_csg_result *boolean_csg_result::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<boolean_csg_result *>(s);
      }
   return NULL;
   }
boolean_csg_result *boolean_csg_result::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<boolean_csg_result *>(s);
      }
   return NULL;
   }
// construction factory
boolean_csg_result *boolean_csg_result::Construct() {
   boolean_csg_result *result = NULL;

   // create the boolean_csg_result.
   result = new boolean_csg_result();
   return result;
   }
bool boolean_csg_result::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: boolean_csg_result\r\n");

   // Check for the existence of all required attributes
   if (_operand_1 == NULL) {
      TRACE("ERROR: _operand_1 a required attribute is NULL!\r\n");
      result = false;
      }
   if (_operand_2 == NULL) {
      TRACE("ERROR: _operand_2 a required attribute is NULL!\r\n");
      result = false;
      }
   if (_csg_operator == NULL) {
      TRACE("ERROR: _csg_operator a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
