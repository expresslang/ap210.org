// Source for AP210 application object
//     requirement_allocation

// Precompiled include files
#include <StdAfx.h>

#include "requirement_allocation.h"

// Classes
#include <ee_requirement_occurrence.h>

requirement_allocation::requirement_allocation() {
   initialize();
   }
requirement_allocation::~requirement_allocation() {
   // Free string attributes
   }
// intialize data members
void requirement_allocation::initialize() {
   // Required attributes
   _allocated_requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int requirement_allocation::DynamicType(int ID) {
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
requirement_allocation *requirement_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<requirement_allocation *>(s);
      }
   return NULL;
   }
requirement_allocation *requirement_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<requirement_allocation *>(s);
      }
   return NULL;
   }
// construction factory
requirement_allocation *requirement_allocation::Construct() {
   requirement_allocation *result = NULL;

   // create the requirement_allocation.
   result = new requirement_allocation();
   return result;
   }
bool requirement_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: requirement_allocation\r\n");

   // Check for the existence of all required attributes
   if (_target_product_object == NULL) {
      TRACE("ERROR: _target_product_object a required attribute is NULL!\r\n");
      result = false;
      }
   if (_allocated_requirement == NULL) {
      TRACE("ERROR: _allocated_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
