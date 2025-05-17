// Source for AP210 application object
//     SetOfdesign_intent_modification_planar_shape

// Precompiled include files
#include <StdAfx.h>

#include "SetOfdesign_intent_modification_planar_shape.h"

// Classes
#include <design_intent_modification_planar_shape.h>

SetOfdesign_intent_modification_planar_shape::SetOfdesign_intent_modification_planar_shape() {
   initialize();
   }
SetOfdesign_intent_modification_planar_shape::~SetOfdesign_intent_modification_planar_shape() {
   // Free string attributes
   }
// intialize data members
void SetOfdesign_intent_modification_planar_shape::initialize() {
   // Required attributes
   _design_intent_modification_planar_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfdesign_intent_modification_planar_shape::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfdesign_intent_modification_planar_shape *SetOfdesign_intent_modification_planar_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfdesign_intent_modification_planar_shape *>(s);
      }
   return NULL;
   }
SetOfdesign_intent_modification_planar_shape *SetOfdesign_intent_modification_planar_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfdesign_intent_modification_planar_shape *>(s);
      }
   return NULL;
   }
// construction factory
SetOfdesign_intent_modification_planar_shape *SetOfdesign_intent_modification_planar_shape::Construct() {
   SetOfdesign_intent_modification_planar_shape *result = NULL;

   // create the SetOfdesign_intent_modification_planar_shape.
   result = new SetOfdesign_intent_modification_planar_shape();
   return result;
   }
bool SetOfdesign_intent_modification_planar_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfdesign_intent_modification_planar_shape\r\n");

   // Check for the existence of all required attributes
   if (_design_intent_modification_planar_shape == NULL) {
      TRACE("ERROR: _design_intent_modification_planar_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
