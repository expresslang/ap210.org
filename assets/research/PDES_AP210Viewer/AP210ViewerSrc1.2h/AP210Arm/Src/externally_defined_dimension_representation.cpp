// Source for AP210 application object
//     externally_defined_dimension_representation

// Precompiled include files
#include <StdAfx.h>

#include "externally_defined_dimension_representation.h"

// Classes
#include <data_element.h>

externally_defined_dimension_representation::externally_defined_dimension_representation() {
   initialize();
   }
externally_defined_dimension_representation::~externally_defined_dimension_representation() {
   // Free string attributes
   }
// intialize data members
void externally_defined_dimension_representation::initialize() {
   // Required attributes

   // Optional attributes
   _dimension_value = NULL;
   }
// Runtime type identification
int externally_defined_dimension_representation::DynamicType(int ID) {
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
externally_defined_dimension_representation *externally_defined_dimension_representation::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<externally_defined_dimension_representation *>(s);
      }
   return NULL;
   }
externally_defined_dimension_representation *externally_defined_dimension_representation::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<externally_defined_dimension_representation *>(s);
      }
   return NULL;
   }
// construction factory
externally_defined_dimension_representation *externally_defined_dimension_representation::Construct() {
   externally_defined_dimension_representation *result = NULL;

   // create the externally_defined_dimension_representation.
   result = new externally_defined_dimension_representation();
   return result;
   }
bool externally_defined_dimension_representation::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: externally_defined_dimension_representation\r\n");

   // Check for the existence of all required attributes
   if (_definitions == NULL) {
      TRACE("ERROR: _definitions a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (shape_dimension_representation::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
