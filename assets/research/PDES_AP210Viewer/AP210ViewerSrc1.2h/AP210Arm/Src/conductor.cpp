// Source for AP210 application object
//     conductor

// Precompiled include files
#include <StdAfx.h>

#include "conductor.h"

// Classes
#include <intra_stratum_join_relationship.h>

conductor::conductor() {
   initialize();
   }
conductor::~conductor() {
   // Free string attributes
   }
// intialize data members
void conductor::initialize() {
   // Required attributes
   _implementation_requirement = NULL;

   // Optional attributes
   }
// Runtime type identification
int conductor::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum_feature::DynamicType(ID);
      }
   return result;
   }
conductor *conductor::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conductor *>(s);
      }
   return NULL;
   }
conductor *conductor::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conductor *>(s);
      }
   return NULL;
   }
// construction factory
conductor *conductor::Construct() {
   conductor *result = NULL;

   // create the conductor.
   result = new conductor();
   return result;
   }
bool conductor::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conductor\r\n");

   // Check for the existence of all required attributes
   if (_implementation_requirement == NULL) {
      TRACE("ERROR: _implementation_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
