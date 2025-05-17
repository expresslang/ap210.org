// Source for AP210 application object
//     contact_size_dependent_land

// Precompiled include files
#include <StdAfx.h>

#include "contact_size_dependent_land.h"

// Classes

contact_size_dependent_land::contact_size_dependent_land() {
   initialize();
   }
contact_size_dependent_land::~contact_size_dependent_land() {
   // Free string attributes
   }
// intialize data members
void contact_size_dependent_land::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int contact_size_dependent_land::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = land::DynamicType(ID);
      }
   return result;
   }
contact_size_dependent_land *contact_size_dependent_land::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<contact_size_dependent_land *>(s);
      }
   return NULL;
   }
contact_size_dependent_land *contact_size_dependent_land::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<contact_size_dependent_land *>(s);
      }
   return NULL;
   }
// construction factory
contact_size_dependent_land *contact_size_dependent_land::Construct() {
   contact_size_dependent_land *result = NULL;

   // create the contact_size_dependent_land.
   result = new contact_size_dependent_land();
   return result;
   }
bool contact_size_dependent_land::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: contact_size_dependent_land\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (land::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
