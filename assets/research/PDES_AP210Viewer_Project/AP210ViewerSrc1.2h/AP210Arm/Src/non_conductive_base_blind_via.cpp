// Source for AP210 application object
//     non_conductive_base_blind_via

// Precompiled include files
#include <StdAfx.h>

#include "non_conductive_base_blind_via.h"

// Classes

non_conductive_base_blind_via::non_conductive_base_blind_via() {
   initialize();
   }
non_conductive_base_blind_via::~non_conductive_base_blind_via() {
   // Free string attributes
   }
// intialize data members
void non_conductive_base_blind_via::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int non_conductive_base_blind_via::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = blind_via::DynamicType(ID);
      }
   return result;
   }
non_conductive_base_blind_via *non_conductive_base_blind_via::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<non_conductive_base_blind_via *>(s);
      }
   return NULL;
   }
non_conductive_base_blind_via *non_conductive_base_blind_via::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<non_conductive_base_blind_via *>(s);
      }
   return NULL;
   }
// construction factory
non_conductive_base_blind_via *non_conductive_base_blind_via::Construct() {
   non_conductive_base_blind_via *result = NULL;

   // create the non_conductive_base_blind_via.
   result = new non_conductive_base_blind_via();
   return result;
   }
bool non_conductive_base_blind_via::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: non_conductive_base_blind_via\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (blind_via::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
