// Source for AP210 application object
//     specification_allocation

// Precompiled include files
#include <StdAfx.h>

#include "specification_allocation.h"

// Classes
#include <ee_specification.h>

specification_allocation::specification_allocation() {
   initialize();
   }
specification_allocation::~specification_allocation() {
   // Free string attributes
   }
// intialize data members
void specification_allocation::initialize() {
   // Required attributes
   _allocated_specification = NULL;

   // Optional attributes
   }
// Runtime type identification
int specification_allocation::DynamicType(int ID) {
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
specification_allocation *specification_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<specification_allocation *>(s);
      }
   return NULL;
   }
specification_allocation *specification_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<specification_allocation *>(s);
      }
   return NULL;
   }
// construction factory
specification_allocation *specification_allocation::Construct() {
   specification_allocation *result = NULL;

   // create the specification_allocation.
   result = new specification_allocation();
   return result;
   }
bool specification_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: specification_allocation\r\n");

   // Check for the existence of all required attributes
   if (_allocated_specification == NULL) {
      TRACE("ERROR: _allocated_specification a required attribute is NULL!\r\n");
      result = false;
      }
   if (_target_product_object == NULL) {
      TRACE("ERROR: _target_product_object a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
