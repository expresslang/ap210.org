// Source for AP210 application object
//     singular_dimension_representation

// Precompiled include files
#include <StdAfx.h>

#include "singular_dimension_representation.h"

// Classes
#include <data_element.h>

singular_dimension_representation::singular_dimension_representation() {
   initialize();
   }
singular_dimension_representation::~singular_dimension_representation() {
   // Free string attributes
   }
// intialize data members
void singular_dimension_representation::initialize() {
   // Required attributes
   _dimension_value = NULL;

   // Optional attributes
   }
// Runtime type identification
int singular_dimension_representation::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = shape_dimension_representation::DynamicType(ID);
      }
   return result;
   }
singular_dimension_representation *singular_dimension_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<singular_dimension_representation *>(s);
      }
   return NULL;
   }
singular_dimension_representation *singular_dimension_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<singular_dimension_representation *>(s);
      }
   return NULL;
   }
// construction factory
singular_dimension_representation *singular_dimension_representation::Construct() {
   singular_dimension_representation *result = NULL;

   // create the singular_dimension_representation.
   result = new singular_dimension_representation();
   return result;
   }
bool singular_dimension_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: singular_dimension_representation\r\n");

   // Check for the existence of all required attributes
   if (_dimension_value == NULL) {
      TRACE("ERROR: _dimension_value a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (shape_dimension_representation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
