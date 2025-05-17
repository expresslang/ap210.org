// Source for AP210 application object
//     design_intent_modification_sequence

// Precompiled include files
#include <StdAfx.h>

#include "design_intent_modification_sequence.h"

// Classes
#include <design_intent_modification.h>
#include <design_intent_modification.h>

design_intent_modification_sequence::design_intent_modification_sequence() {
   initialize();
   }
design_intent_modification_sequence::~design_intent_modification_sequence() {
   // Free string attributes
   }
// intialize data members
void design_intent_modification_sequence::initialize() {
   // Required attributes
   _precedent_modification = NULL;
   _subsequent_modification = NULL;

   // Optional attributes
   }
// Runtime type identification
int design_intent_modification_sequence::DynamicType(int ID) {
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
design_intent_modification_sequence *design_intent_modification_sequence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_intent_modification_sequence *>(s);
      }
   return NULL;
   }
design_intent_modification_sequence *design_intent_modification_sequence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_intent_modification_sequence *>(s);
      }
   return NULL;
   }
// construction factory
design_intent_modification_sequence *design_intent_modification_sequence::Construct() {
   design_intent_modification_sequence *result = NULL;

   // create the design_intent_modification_sequence.
   result = new design_intent_modification_sequence();
   return result;
   }
bool design_intent_modification_sequence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_intent_modification_sequence\r\n");

   // Check for the existence of all required attributes
   if (_precedent_modification == NULL) {
      TRACE("ERROR: _precedent_modification a required attribute is NULL!\r\n");
      result = false;
      }
   if (_subsequent_modification == NULL) {
      TRACE("ERROR: _subsequent_modification a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
