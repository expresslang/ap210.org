// Source for AP210 application object
//     composite_feature_relating_position_tolerance

// Precompiled include files
#include <StdAfx.h>

#include "composite_feature_relating_position_tolerance.h"

// Classes

composite_feature_relating_position_tolerance::composite_feature_relating_position_tolerance() {
   initialize();
   }
composite_feature_relating_position_tolerance::~composite_feature_relating_position_tolerance() {
   // Free string attributes
   }
// intialize data members
void composite_feature_relating_position_tolerance::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int composite_feature_relating_position_tolerance::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = position_tolerance::DynamicType(ID);
      }
   return result;
   }
composite_feature_relating_position_tolerance *composite_feature_relating_position_tolerance::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<composite_feature_relating_position_tolerance *>(s);
      }
   return NULL;
   }
composite_feature_relating_position_tolerance *composite_feature_relating_position_tolerance::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<composite_feature_relating_position_tolerance *>(s);
      }
   return NULL;
   }
// construction factory
composite_feature_relating_position_tolerance *composite_feature_relating_position_tolerance::Construct() {
   composite_feature_relating_position_tolerance *result = NULL;

   // create the composite_feature_relating_position_tolerance.
   result = new composite_feature_relating_position_tolerance();
   return result;
   }
bool composite_feature_relating_position_tolerance::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: composite_feature_relating_position_tolerance\r\n");

   // Check for the existence of all required attributes
   if (_refined_control == NULL) {
      TRACE("ERROR: _refined_control a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (position_tolerance::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
