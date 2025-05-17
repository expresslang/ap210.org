// Source for AP210 application object
//     stratum_surface_shape

// Precompiled include files
#include <StdAfx.h>

#include "stratum_surface_shape.h"

// Classes
#include <stratum_surface.h>

stratum_surface_shape::stratum_surface_shape() {
   initialize();
   }
stratum_surface_shape::~stratum_surface_shape() {
   // Free string attributes
   }
// intialize data members
void stratum_surface_shape::initialize() {
   // Required attributes
   _of_surface = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_surface_shape::DynamicType(int ID) {
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
stratum_surface_shape *stratum_surface_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_surface_shape *>(s);
      }
   return NULL;
   }
stratum_surface_shape *stratum_surface_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_surface_shape *>(s);
      }
   return NULL;
   }
// construction factory
stratum_surface_shape *stratum_surface_shape::Construct() {
   stratum_surface_shape *result = NULL;

   // create the stratum_surface_shape.
   result = new stratum_surface_shape();
   return result;
   }
bool stratum_surface_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_surface_shape\r\n");

   // Check for the existence of all required attributes
   if (_of_surface == NULL) {
      TRACE("ERROR: _of_surface a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
