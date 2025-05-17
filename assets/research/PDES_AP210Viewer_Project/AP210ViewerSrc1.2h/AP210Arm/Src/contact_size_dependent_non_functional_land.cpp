// Source for AP210 application object
//     contact_size_dependent_non_functional_land

// Precompiled include files
#include <StdAfx.h>

#include "contact_size_dependent_non_functional_land.h"

// Classes

contact_size_dependent_non_functional_land::contact_size_dependent_non_functional_land() {
   initialize();
   }
contact_size_dependent_non_functional_land::~contact_size_dependent_non_functional_land() {
   // Free string attributes
   }
// intialize data members
void contact_size_dependent_non_functional_land::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int contact_size_dependent_non_functional_land::DynamicType(int ID) {
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
contact_size_dependent_non_functional_land *contact_size_dependent_non_functional_land::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<contact_size_dependent_non_functional_land *>(s);
      }
   return NULL;
   }
contact_size_dependent_non_functional_land *contact_size_dependent_non_functional_land::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<contact_size_dependent_non_functional_land *>(s);
      }
   return NULL;
   }
// construction factory
contact_size_dependent_non_functional_land *contact_size_dependent_non_functional_land::Construct() {
   contact_size_dependent_non_functional_land *result = NULL;

   // create the contact_size_dependent_non_functional_land.
   result = new contact_size_dependent_non_functional_land();
   return result;
   }
bool contact_size_dependent_non_functional_land::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: contact_size_dependent_non_functional_land\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (non_functional_land::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
