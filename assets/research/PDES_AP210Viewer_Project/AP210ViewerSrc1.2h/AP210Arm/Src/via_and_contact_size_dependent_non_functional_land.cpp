// Source for AP210 application object
//     via_and_contact_size_dependent_non_functional_land

// Precompiled include files
#include <StdAfx.h>

#include "via_and_contact_size_dependent_non_functional_land.h"

// Classes
#include <via.h>

via_and_contact_size_dependent_non_functional_land::via_and_contact_size_dependent_non_functional_land() {
   initialize();
   }
via_and_contact_size_dependent_non_functional_land::~via_and_contact_size_dependent_non_functional_land() {
   // Free string attributes
   }
// intialize data members
void via_and_contact_size_dependent_non_functional_land::initialize() {
   // Required attributes
   _reference_via = NULL;

   // Optional attributes
   }
// Runtime type identification
int via_and_contact_size_dependent_non_functional_land::DynamicType(int ID) {
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
via_and_contact_size_dependent_non_functional_land *via_and_contact_size_dependent_non_functional_land::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<via_and_contact_size_dependent_non_functional_land *>(s);
      }
   return NULL;
   }
via_and_contact_size_dependent_non_functional_land *via_and_contact_size_dependent_non_functional_land::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<via_and_contact_size_dependent_non_functional_land *>(s);
      }
   return NULL;
   }
// construction factory
via_and_contact_size_dependent_non_functional_land *via_and_contact_size_dependent_non_functional_land::Construct() {
   via_and_contact_size_dependent_non_functional_land *result = NULL;

   // create the via_and_contact_size_dependent_non_functional_land.
   result = new via_and_contact_size_dependent_non_functional_land();
   return result;
   }
bool via_and_contact_size_dependent_non_functional_land::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: via_and_contact_size_dependent_non_functional_land\r\n");

   // Check for the existence of all required attributes
   if (_reference_via == NULL) {
      TRACE("ERROR: _reference_via a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (non_functional_land::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
