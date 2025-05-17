// Source for AP210 application object
//     angular_size_dimension

// Precompiled include files
#include <StdAfx.h>

#include "angular_size_dimension.h"

// Classes

angular_size_dimension::angular_size_dimension() {
   initialize();
   }
angular_size_dimension::~angular_size_dimension() {
   // Free string attributes
   }
// intialize data members
void angular_size_dimension::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int angular_size_dimension::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = dimensional_size::DynamicType(ID);
      }
   return result;
   }
angular_size_dimension *angular_size_dimension::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<angular_size_dimension *>(s);
      }
   return NULL;
   }
angular_size_dimension *angular_size_dimension::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<angular_size_dimension *>(s);
      }
   return NULL;
   }
// construction factory
angular_size_dimension *angular_size_dimension::Construct() {
   angular_size_dimension *result = NULL;

   // create the angular_size_dimension.
   result = new angular_size_dimension();
   return result;
   }
bool angular_size_dimension::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: angular_size_dimension\r\n");

   // Check for the existence of all required attributes
   if (_half_angle == NULL) {
      TRACE("ERROR: _half_angle a required attribute is NULL!\r\n");
      result = false;
      }
   if (_major_angle == NULL) {
      TRACE("ERROR: _major_angle a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (dimensional_size::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
