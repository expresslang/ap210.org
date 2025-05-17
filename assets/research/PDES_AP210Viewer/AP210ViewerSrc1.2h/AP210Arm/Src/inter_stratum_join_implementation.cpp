// Source for AP210 application object
//     inter_stratum_join_implementation

// Precompiled include files
#include <StdAfx.h>

#include "inter_stratum_join_implementation.h"

// Classes
#include <inter_stratum_join_relationship.h>

inter_stratum_join_implementation::inter_stratum_join_implementation() {
   initialize();
   }
inter_stratum_join_implementation::~inter_stratum_join_implementation() {
   // Free string attributes
   }
// intialize data members
void inter_stratum_join_implementation::initialize() {
   // Required attributes
   _topological_requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int inter_stratum_join_implementation::DynamicType(int ID) {
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
inter_stratum_join_implementation *inter_stratum_join_implementation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<inter_stratum_join_implementation *>(s);
      }
   return NULL;
   }
inter_stratum_join_implementation *inter_stratum_join_implementation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<inter_stratum_join_implementation *>(s);
      }
   return NULL;
   }
// construction factory
inter_stratum_join_implementation *inter_stratum_join_implementation::Construct() {
   inter_stratum_join_implementation *result = NULL;

   // create the inter_stratum_join_implementation.
   result = new inter_stratum_join_implementation();
   return result;
   }
bool inter_stratum_join_implementation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: inter_stratum_join_implementation\r\n");

   // Check for the existence of all required attributes
   if (_topological_requirement == NULL) {
      TRACE("ERROR: _topological_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
