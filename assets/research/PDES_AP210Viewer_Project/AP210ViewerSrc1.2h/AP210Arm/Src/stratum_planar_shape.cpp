// Source for AP210 application object
//     stratum_planar_shape

// Precompiled include files
#include <StdAfx.h>

#include "stratum_planar_shape.h"

// Classes
#include <stratum.h>

stratum_planar_shape::stratum_planar_shape() {
   initialize();
   }
stratum_planar_shape::~stratum_planar_shape() {
   // Free string attributes
   }
// intialize data members
void stratum_planar_shape::initialize() {
   // Required attributes
   _shape_characterized_stratum = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_planar_shape::DynamicType(int ID) {
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
stratum_planar_shape *stratum_planar_shape::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_planar_shape *>(s);
      }
   return NULL;
   }
stratum_planar_shape *stratum_planar_shape::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_planar_shape *>(s);
      }
   return NULL;
   }
// construction factory
stratum_planar_shape *stratum_planar_shape::Construct() {
   stratum_planar_shape *result = NULL;

   // create the stratum_planar_shape.
   result = new stratum_planar_shape();
   return result;
   }
bool stratum_planar_shape::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_planar_shape\r\n");

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
