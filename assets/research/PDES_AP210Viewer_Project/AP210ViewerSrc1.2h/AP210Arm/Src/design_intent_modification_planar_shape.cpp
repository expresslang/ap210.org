// Source for AP210 application object
//     design_intent_modification_planar_shape

// Precompiled include files
#include <StdAfx.h>

#include "design_intent_modification_planar_shape.h"

// Classes
#include <design_intent_modification.h>
#include <planar_projected_shape.h>

design_intent_modification_planar_shape::design_intent_modification_planar_shape() {
   initialize();
   }
design_intent_modification_planar_shape::~design_intent_modification_planar_shape() {
   // Free string attributes
   }
// intialize data members
void design_intent_modification_planar_shape::initialize() {
   // Required attributes
   _represented_design_intent_modification = NULL;
   _shape_representation = NULL;

   // Optional attributes
   }
// Runtime type identification
int design_intent_modification_planar_shape::DynamicType(int ID) {
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
design_intent_modification_planar_shape *design_intent_modification_planar_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_intent_modification_planar_shape *>(s);
      }
   return NULL;
   }
design_intent_modification_planar_shape *design_intent_modification_planar_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_intent_modification_planar_shape *>(s);
      }
   return NULL;
   }
// construction factory
design_intent_modification_planar_shape *design_intent_modification_planar_shape::Construct() {
   design_intent_modification_planar_shape *result = NULL;

   // create the design_intent_modification_planar_shape.
   result = new design_intent_modification_planar_shape();
   return result;
   }
bool design_intent_modification_planar_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_intent_modification_planar_shape\r\n");

   // Check for the existence of all required attributes
   if (_represented_design_intent_modification == NULL) {
      TRACE("ERROR: _represented_design_intent_modification a required attribute is NULL!\r\n");
      result = false;
      }
   if (_shape_representation == NULL) {
      TRACE("ERROR: _shape_representation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
