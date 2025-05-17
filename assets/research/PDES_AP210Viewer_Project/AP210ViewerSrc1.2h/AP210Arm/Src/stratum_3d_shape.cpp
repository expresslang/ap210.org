// Source for AP210 application object
//     stratum_3d_shape

// Precompiled include files
#include <StdAfx.h>

#include "stratum_3d_shape.h"

// Classes
#include <stratum.h>

stratum_3d_shape::stratum_3d_shape() {
   initialize();
   }
stratum_3d_shape::~stratum_3d_shape() {
   // Free string attributes
   }
// intialize data members
void stratum_3d_shape::initialize() {
   // Required attributes
   _shape_characterized_stratum = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_3d_shape::DynamicType(int ID) {
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
stratum_3d_shape *stratum_3d_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_3d_shape *>(s);
      }
   return NULL;
   }
stratum_3d_shape *stratum_3d_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_3d_shape *>(s);
      }
   return NULL;
   }
// construction factory
stratum_3d_shape *stratum_3d_shape::Construct() {
   stratum_3d_shape *result = NULL;

   // create the stratum_3d_shape.
   result = new stratum_3d_shape();
   return result;
   }
bool stratum_3d_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_3d_shape\r\n");

   // Check for the existence of all required attributes
   if (_shape_characterized_stratum == NULL) {
      TRACE("ERROR: _shape_characterized_stratum a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
