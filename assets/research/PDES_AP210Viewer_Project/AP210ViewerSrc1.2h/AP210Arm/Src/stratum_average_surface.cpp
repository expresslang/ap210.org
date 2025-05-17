// Source for AP210 application object
//     stratum_average_surface

// Precompiled include files
#include <StdAfx.h>

#include "stratum_average_surface.h"

// Classes
#include <stratum.h>

stratum_average_surface::stratum_average_surface() {
   initialize();
   }
stratum_average_surface::~stratum_average_surface() {
   // Free string attributes
   }
// intialize data members
void stratum_average_surface::initialize() {
   // Required attributes
   _of_stratum = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_average_surface::DynamicType(int ID) {
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
stratum_average_surface *stratum_average_surface::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_average_surface *>(s);
      }
   return NULL;
   }
stratum_average_surface *stratum_average_surface::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_average_surface *>(s);
      }
   return NULL;
   }
// construction factory
stratum_average_surface *stratum_average_surface::Construct() {
   stratum_average_surface *result = NULL;

   // create the stratum_average_surface.
   result = new stratum_average_surface();
   return result;
   }
bool stratum_average_surface::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_average_surface\r\n");

   // Check for the existence of all required attributes
   if (_of_stratum == NULL) {
      TRACE("ERROR: _of_stratum a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
