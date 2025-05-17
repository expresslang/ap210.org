// Source for AP210 application object
//     stratum_surface

// Precompiled include files
#include <StdAfx.h>

#include "stratum_surface.h"

// Classes
#include <stratum.h>

stratum_surface::stratum_surface() {
   initialize();
   }
stratum_surface::~stratum_surface() {
   // Free string attributes
   }
// intialize data members
void stratum_surface::initialize() {
   // Required attributes
   _of_stratum = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_surface::DynamicType(int ID) {
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
stratum_surface *stratum_surface::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_surface *>(s);
      }
   return NULL;
   }
stratum_surface *stratum_surface::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_surface *>(s);
      }
   return NULL;
   }
// construction factory
stratum_surface *stratum_surface::Construct() {
   stratum_surface *result = NULL;

   // create the stratum_surface.
   result = new stratum_surface();
   return result;
   }
bool stratum_surface::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_surface\r\n");

   // Check for the existence of all required attributes
   if (_of_stratum == NULL) {
      TRACE("ERROR: _of_stratum a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
