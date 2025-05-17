// Source for AP210 application object
//     plated_conductive_base_blind_via

// Precompiled include files
#include <StdAfx.h>

#include "plated_conductive_base_blind_via.h"

// Classes

plated_conductive_base_blind_via::plated_conductive_base_blind_via() {
   initialize();
   }
plated_conductive_base_blind_via::~plated_conductive_base_blind_via() {
   // Free string attributes
   }
// intialize data members
void plated_conductive_base_blind_via::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int plated_conductive_base_blind_via::DynamicType(int ID) {
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
plated_conductive_base_blind_via *plated_conductive_base_blind_via::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<plated_conductive_base_blind_via *>(s);
      }
   return NULL;
   }
plated_conductive_base_blind_via *plated_conductive_base_blind_via::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<plated_conductive_base_blind_via *>(s);
      }
   return NULL;
   }
// construction factory
plated_conductive_base_blind_via *plated_conductive_base_blind_via::Construct() {
   plated_conductive_base_blind_via *result = NULL;

   // create the plated_conductive_base_blind_via.
   result = new plated_conductive_base_blind_via();
   return result;
   }
bool plated_conductive_base_blind_via::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: plated_conductive_base_blind_via\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (blind_via::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
