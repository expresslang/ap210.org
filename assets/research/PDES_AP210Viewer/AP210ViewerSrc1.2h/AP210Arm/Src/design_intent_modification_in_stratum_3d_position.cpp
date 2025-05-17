// Source for AP210 application object
//     design_intent_modification_in_stratum_3d_position

// Precompiled include files
#include <StdAfx.h>

#include "design_intent_modification_in_stratum_3d_position.h"

// Classes
#include <stratum_3d_shape.h>
#include <axis_placement_3d.h>

design_intent_modification_in_stratum_3d_position::design_intent_modification_in_stratum_3d_position() {
   initialize();
   }
design_intent_modification_in_stratum_3d_position::~design_intent_modification_in_stratum_3d_position() {
   // Free string attributes
   }
// intialize data members
void design_intent_modification_in_stratum_3d_position::initialize() {
   // Required attributes
   _stratum_shape = NULL;
   _transformation = NULL;

   // Optional attributes
   }
// Runtime type identification
int design_intent_modification_in_stratum_3d_position::DynamicType(int ID) {
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
design_intent_modification_in_stratum_3d_position *design_intent_modification_in_stratum_3d_position::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<design_intent_modification_in_stratum_3d_position *>(s);
      }
   return NULL;
   }
design_intent_modification_in_stratum_3d_position *design_intent_modification_in_stratum_3d_position::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<design_intent_modification_in_stratum_3d_position *>(s);
      }
   return NULL;
   }
// construction factory
design_intent_modification_in_stratum_3d_position *design_intent_modification_in_stratum_3d_position::Construct() {
   design_intent_modification_in_stratum_3d_position *result = NULL;

   // create the design_intent_modification_in_stratum_3d_position.
   result = new design_intent_modification_in_stratum_3d_position();
   return result;
   }
bool design_intent_modification_in_stratum_3d_position::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: design_intent_modification_in_stratum_3d_position\r\n");

   // Check for the existence of all required attributes
   if (_stratum_shape == NULL) {
      TRACE("ERROR: _stratum_shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_transformation == NULL) {
      TRACE("ERROR: _transformation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_feature_shape == NULL) {
      TRACE("ERROR: _feature_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
