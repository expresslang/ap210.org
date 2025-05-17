// Source for AP210 application object
//     design_intent_modification

// Precompiled include files
#include <StdAfx.h>

#include "design_intent_modification.h"

// Classes
#include <stratum_feature.h>

design_intent_modification::design_intent_modification() {
   initialize();
   }
design_intent_modification::~design_intent_modification() {
   // Free string attributes
   }
// intialize data members
void design_intent_modification::initialize() {
   // Required attributes
   _design_intent = NULL;

   // Optional attributes
   }
// Runtime type identification
int design_intent_modification::DynamicType(int ID) {
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
design_intent_modification *design_intent_modification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_intent_modification *>(s);
      }
   return NULL;
   }
design_intent_modification *design_intent_modification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_intent_modification *>(s);
      }
   return NULL;
   }
// construction factory
design_intent_modification *design_intent_modification::Construct() {
   design_intent_modification *result = NULL;

   // create the design_intent_modification.
   result = new design_intent_modification();
   return result;
   }
bool design_intent_modification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_intent_modification\r\n");

   // Check for the existence of all required attributes
   if (_design_intent == NULL) {
      TRACE("ERROR: _design_intent a required attribute is NULL!\r\n");
      result = false;
      }
   if (_modification_causal_item == NULL) {
      TRACE("ERROR: _modification_causal_item a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
