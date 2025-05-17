// Source for AP210 application object
//     SetOfvector

// Precompiled include files
#include <StdAfx.h>

#include "SetOfvector.h"

// Classes
#include <vector.h>

SetOfvector::SetOfvector() {
   initialize();
   }
SetOfvector::~SetOfvector() {
   // Free string attributes
   }
// intialize data members
void SetOfvector::initialize() {
   // Required attributes
   _vector = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfvector::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfvector *SetOfvector::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfvector *>(s);
      }
   return NULL;
   }
SetOfvector *SetOfvector::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfvector *>(s);
      }
   return NULL;
   }
// construction factory
SetOfvector *SetOfvector::Construct() {
   SetOfvector *result = NULL;

   // create the SetOfvector.
   result = new SetOfvector();
   return result;
   }
bool SetOfvector::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfvector\r\n");

   // Check for the existence of all required attributes
   if (_vector == NULL) {
      TRACE("ERROR: _vector a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
