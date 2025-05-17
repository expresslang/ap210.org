// Source for AP210 application object
//     unsupported_passage_dependent_non_functional_land

// Precompiled include files
#include <StdAfx.h>

#include "unsupported_passage_dependent_non_functional_land.h"

// Classes
#include <unsupported_passage.h>

unsupported_passage_dependent_non_functional_land::unsupported_passage_dependent_non_functional_land() {
   initialize();
   }
unsupported_passage_dependent_non_functional_land::~unsupported_passage_dependent_non_functional_land() {
   // Free string attributes
   }
// intialize data members
void unsupported_passage_dependent_non_functional_land::initialize() {
   // Required attributes
   _reference_passage = NULL;

   // Optional attributes
   }
// Runtime type identification
int unsupported_passage_dependent_non_functional_land::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = non_functional_land::DynamicType(ID);
      }
   return result;
   }
unsupported_passage_dependent_non_functional_land *unsupported_passage_dependent_non_functional_land::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<unsupported_passage_dependent_non_functional_land *>(s);
      }
   return NULL;
   }
unsupported_passage_dependent_non_functional_land *unsupported_passage_dependent_non_functional_land::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<unsupported_passage_dependent_non_functional_land *>(s);
      }
   return NULL;
   }
// construction factory
unsupported_passage_dependent_non_functional_land *unsupported_passage_dependent_non_functional_land::Construct() {
   unsupported_passage_dependent_non_functional_land *result = NULL;

   // create the unsupported_passage_dependent_non_functional_land.
   result = new unsupported_passage_dependent_non_functional_land();
   return result;
   }
bool unsupported_passage_dependent_non_functional_land::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: unsupported_passage_dependent_non_functional_land\r\n");

   // Check for the existence of all required attributes
   if (_reference_passage == NULL) {
      TRACE("ERROR: _reference_passage a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (non_functional_land::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
