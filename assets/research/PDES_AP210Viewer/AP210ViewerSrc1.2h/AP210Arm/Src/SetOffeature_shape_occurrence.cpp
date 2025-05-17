// Source for AP210 application object
//     SetOffeature_shape_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "SetOffeature_shape_occurrence.h"

// Classes
#include <feature_shape_occurrence.h>

SetOffeature_shape_occurrence::SetOffeature_shape_occurrence() {
   initialize();
   }
SetOffeature_shape_occurrence::~SetOffeature_shape_occurrence() {
   // Free string attributes
   }
// intialize data members
void SetOffeature_shape_occurrence::initialize() {
   // Required attributes
   _feature_shape_occurrence = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOffeature_shape_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOffeature_shape_occurrence *SetOffeature_shape_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOffeature_shape_occurrence *>(s);
      }
   return NULL;
   }
SetOffeature_shape_occurrence *SetOffeature_shape_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOffeature_shape_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
SetOffeature_shape_occurrence *SetOffeature_shape_occurrence::Construct() {
   SetOffeature_shape_occurrence *result = NULL;

   // create the SetOffeature_shape_occurrence.
   result = new SetOffeature_shape_occurrence();
   return result;
   }
bool SetOffeature_shape_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOffeature_shape_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_feature_shape_occurrence == NULL) {
      TRACE("ERROR: _feature_shape_occurrence a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
