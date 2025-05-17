// Source for AP210 application object
//     composite_signal_property

// Precompiled include files
#include <StdAfx.h>

#include "composite_signal_property.h"

// Classes

composite_signal_property::composite_signal_property() {
   initialize();
   }
composite_signal_property::~composite_signal_property() {
   // Free string attributes
   }
// intialize data members
void composite_signal_property::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int composite_signal_property::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = signal_property::DynamicType(ID);
      }
   return result;
   }
composite_signal_property *composite_signal_property::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<composite_signal_property *>(s);
      }
   return NULL;
   }
composite_signal_property *composite_signal_property::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<composite_signal_property *>(s);
      }
   return NULL;
   }
// construction factory
composite_signal_property *composite_signal_property::Construct() {
   composite_signal_property *result = NULL;

   // create the composite_signal_property.
   result = new composite_signal_property();
   return result;
   }
bool composite_signal_property::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: composite_signal_property\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (signal_property::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
