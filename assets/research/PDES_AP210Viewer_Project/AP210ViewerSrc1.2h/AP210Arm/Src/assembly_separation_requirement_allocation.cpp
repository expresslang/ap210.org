// Source for AP210 application object
//     assembly_separation_requirement_allocation

// Precompiled include files
#include <StdAfx.h>

#include "assembly_separation_requirement_allocation.h"

// Classes

assembly_separation_requirement_allocation::assembly_separation_requirement_allocation() {
   initialize();
   }
assembly_separation_requirement_allocation::~assembly_separation_requirement_allocation() {
   // Free string attributes
   }
// intialize data members
void assembly_separation_requirement_allocation::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int assembly_separation_requirement_allocation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_requirement_allocation::DynamicType(ID);
      }
   return result;
   }
assembly_separation_requirement_allocation *assembly_separation_requirement_allocation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_separation_requirement_allocation *>(s);
      }
   return NULL;
   }
assembly_separation_requirement_allocation *assembly_separation_requirement_allocation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_separation_requirement_allocation *>(s);
      }
   return NULL;
   }
// construction factory
assembly_separation_requirement_allocation *assembly_separation_requirement_allocation::Construct() {
   assembly_separation_requirement_allocation *result = NULL;

   // create the assembly_separation_requirement_allocation.
   result = new assembly_separation_requirement_allocation();
   return result;
   }
bool assembly_separation_requirement_allocation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_separation_requirement_allocation\r\n");

   // Check for the existence of all required attributes
   if (_disjoint_assignment == NULL) {
      TRACE("ERROR: _disjoint_assignment a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (assembly_requirement_allocation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
