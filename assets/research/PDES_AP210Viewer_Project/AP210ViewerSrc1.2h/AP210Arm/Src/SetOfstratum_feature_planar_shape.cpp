// Source for AP210 application object
//     SetOfstratum_feature_planar_shape

// Precompiled include files
#include <StdAfx.h>

#include "SetOfstratum_feature_planar_shape.h"

// Classes
#include <stratum_feature_planar_shape.h>

SetOfstratum_feature_planar_shape::SetOfstratum_feature_planar_shape() {
   initialize();
   }
SetOfstratum_feature_planar_shape::~SetOfstratum_feature_planar_shape() {
   // Free string attributes
   }
// intialize data members
void SetOfstratum_feature_planar_shape::initialize() {
   // Required attributes
   _stratum_feature_planar_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfstratum_feature_planar_shape::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfstratum_feature_planar_shape *SetOfstratum_feature_planar_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfstratum_feature_planar_shape *>(s);
      }
   return NULL;
   }
SetOfstratum_feature_planar_shape *SetOfstratum_feature_planar_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfstratum_feature_planar_shape *>(s);
      }
   return NULL;
   }
// construction factory
SetOfstratum_feature_planar_shape *SetOfstratum_feature_planar_shape::Construct() {
   SetOfstratum_feature_planar_shape *result = NULL;

   // create the SetOfstratum_feature_planar_shape.
   result = new SetOfstratum_feature_planar_shape();
   return result;
   }
bool SetOfstratum_feature_planar_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfstratum_feature_planar_shape\r\n");

   // Check for the existence of all required attributes
   if (_stratum_feature_planar_shape == NULL) {
      TRACE("ERROR: _stratum_feature_planar_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
