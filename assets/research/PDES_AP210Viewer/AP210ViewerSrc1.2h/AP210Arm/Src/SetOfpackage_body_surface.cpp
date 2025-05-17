// Source for AP210 application object
//     SetOfpackage_body_surface

// Precompiled include files
#include <StdAfx.h>

#include "SetOfpackage_body_surface.h"

// Classes
#include <package_body_surface.h>

SetOfpackage_body_surface::SetOfpackage_body_surface() {
   initialize();
   }
SetOfpackage_body_surface::~SetOfpackage_body_surface() {
   // Free string attributes
   }
// intialize data members
void SetOfpackage_body_surface::initialize() {
   // Required attributes
   _package_body_surface = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfpackage_body_surface::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfpackage_body_surface *SetOfpackage_body_surface::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfpackage_body_surface *>(s);
      }
   return NULL;
   }
SetOfpackage_body_surface *SetOfpackage_body_surface::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfpackage_body_surface *>(s);
      }
   return NULL;
   }
// construction factory
SetOfpackage_body_surface *SetOfpackage_body_surface::Construct() {
   SetOfpackage_body_surface *result = NULL;

   // create the SetOfpackage_body_surface.
   result = new SetOfpackage_body_surface();
   return result;
   }
bool SetOfpackage_body_surface::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfpackage_body_surface\r\n");

   // Check for the existence of all required attributes
   if (_package_body_surface == NULL) {
      TRACE("ERROR: _package_body_surface a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
