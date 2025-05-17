// Source for AP210 application object
//     bonded_conductive_base_blind_via

// Precompiled include files
#include <StdAfx.h>

#include "bonded_conductive_base_blind_via.h"

// Classes
#include <stratum_feature_conductive_join.h>

bonded_conductive_base_blind_via::bonded_conductive_base_blind_via() {
   initialize();
   }
bonded_conductive_base_blind_via::~bonded_conductive_base_blind_via() {
   // Free string attributes
   }
// intialize data members
void bonded_conductive_base_blind_via::initialize() {
   // Required attributes
   _features_join = NULL;

   // Optional attributes
   }
// Runtime type identification
int bonded_conductive_base_blind_via::DynamicType(int ID) {
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
bonded_conductive_base_blind_via *bonded_conductive_base_blind_via::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<bonded_conductive_base_blind_via *>(s);
      }
   return NULL;
   }
bonded_conductive_base_blind_via *bonded_conductive_base_blind_via::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<bonded_conductive_base_blind_via *>(s);
      }
   return NULL;
   }
// construction factory
bonded_conductive_base_blind_via *bonded_conductive_base_blind_via::Construct() {
   bonded_conductive_base_blind_via *result = NULL;

   // create the bonded_conductive_base_blind_via.
   result = new bonded_conductive_base_blind_via();
   return result;
   }
bool bonded_conductive_base_blind_via::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: bonded_conductive_base_blind_via\r\n");

   // Check for the existence of all required attributes
   if (_features_join == NULL) {
      TRACE("ERROR: _features_join a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (blind_via::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
