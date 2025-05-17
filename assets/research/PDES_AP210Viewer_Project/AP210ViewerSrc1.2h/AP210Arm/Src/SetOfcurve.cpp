// Source for AP210 application object
//     SetOfcurve

// Precompiled include files
#include <StdAfx.h>

#include "SetOfcurve.h"

// Classes
#include <curve.h>

SetOfcurve::SetOfcurve() {
   initialize();
   }
SetOfcurve::~SetOfcurve() {
   // Free string attributes
   }
// intialize data members
void SetOfcurve::initialize() {
   // Required attributes
   _curve = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfcurve::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfcurve *SetOfcurve::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfcurve *>(s);
      }
   return NULL;
   }
SetOfcurve *SetOfcurve::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfcurve *>(s);
      }
   return NULL;
   }
// construction factory
SetOfcurve *SetOfcurve::Construct() {
   SetOfcurve *result = NULL;

   // create the SetOfcurve.
   result = new SetOfcurve();
   return result;
   }
bool SetOfcurve::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfcurve\r\n");

   // Check for the existence of all required attributes
   if (_curve == NULL) {
      TRACE("ERROR: _curve a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
