// Source for AP210 application object
//     design_intent_modification_styled_area_representation

// Precompiled include files
#include <StdAfx.h>

#include "design_intent_modification_styled_area_representation.h"

// Classes
#include <design_intent_modification.h>

design_intent_modification_styled_area_representation::design_intent_modification_styled_area_representation() {
   initialize();
   }
design_intent_modification_styled_area_representation::~design_intent_modification_styled_area_representation() {
   // Free string attributes
   }
// intialize data members
void design_intent_modification_styled_area_representation::initialize() {
   // Required attributes
   _represented_design_intent_modification = NULL;

   // Optional attributes
   }
// Runtime type identification
int design_intent_modification_styled_area_representation::DynamicType(int ID) {
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
design_intent_modification_styled_area_representation *design_intent_modification_styled_area_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_intent_modification_styled_area_representation *>(s);
      }
   return NULL;
   }
design_intent_modification_styled_area_representation *design_intent_modification_styled_area_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_intent_modification_styled_area_representation *>(s);
      }
   return NULL;
   }
// construction factory
design_intent_modification_styled_area_representation *design_intent_modification_styled_area_representation::Construct() {
   design_intent_modification_styled_area_representation *result = NULL;

   // create the design_intent_modification_styled_area_representation.
   result = new design_intent_modification_styled_area_representation();
   return result;
   }
bool design_intent_modification_styled_area_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_intent_modification_styled_area_representation\r\n");

   // Check for the existence of all required attributes
   if (_represented_design_intent_modification == NULL) {
      TRACE("ERROR: _represented_design_intent_modification a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_styled_area_representation == NULL) {
      TRACE("ERROR: _shape_styled_area_representation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
