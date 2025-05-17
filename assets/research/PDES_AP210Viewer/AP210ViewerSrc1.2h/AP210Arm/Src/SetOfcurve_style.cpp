// Source for AP210 application object
//     SetOfcurve_style

// Precompiled include files
#include <StdAfx.h>

#include "SetOfcurve_style.h"

// Classes
#include <curve_style.h>

SetOfcurve_style::SetOfcurve_style() {
   initialize();
   }
SetOfcurve_style::~SetOfcurve_style() {
   // Free string attributes
   }
// intialize data members
void SetOfcurve_style::initialize() {
   // Required attributes
   _curve_style = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfcurve_style::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfcurve_style *SetOfcurve_style::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfcurve_style *>(s);
      }
   return NULL;
   }
SetOfcurve_style *SetOfcurve_style::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfcurve_style *>(s);
      }
   return NULL;
   }
// construction factory
SetOfcurve_style *SetOfcurve_style::Construct() {
   SetOfcurve_style *result = NULL;

   // create the SetOfcurve_style.
   result = new SetOfcurve_style();
   return result;
   }
bool SetOfcurve_style::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfcurve_style\r\n");

   // Check for the existence of all required attributes
   if (_curve_style == NULL) {
      TRACE("ERROR: _curve_style a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
