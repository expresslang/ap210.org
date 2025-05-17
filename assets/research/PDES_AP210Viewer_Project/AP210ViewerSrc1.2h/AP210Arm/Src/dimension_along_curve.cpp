// Source for AP210 application object
//     dimension_along_curve

// Precompiled include files
#include <StdAfx.h>

#include "dimension_along_curve.h"

// Classes
#include <shape_element.h>

dimension_along_curve::dimension_along_curve() {
   initialize();
   }
dimension_along_curve::~dimension_along_curve() {
   // Free string attributes
   }
// intialize data members
void dimension_along_curve::initialize() {
   // Required attributes
   _path = NULL;

   // Optional attributes
   }
// Runtime type identification
int dimension_along_curve::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = dimensional_location::DynamicType(ID);
      }
   return result;
   }
dimension_along_curve *dimension_along_curve::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimension_along_curve *>(s);
      }
   return NULL;
   }
dimension_along_curve *dimension_along_curve::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimension_along_curve *>(s);
      }
   return NULL;
   }
// construction factory
dimension_along_curve *dimension_along_curve::Construct() {
   dimension_along_curve *result = NULL;

   // create the dimension_along_curve.
   result = new dimension_along_curve();
   return result;
   }
bool dimension_along_curve::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimension_along_curve\r\n");

   // Check for the existence of all required attributes
   if (_path == NULL) {
      TRACE("ERROR: _path a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (dimensional_location::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
