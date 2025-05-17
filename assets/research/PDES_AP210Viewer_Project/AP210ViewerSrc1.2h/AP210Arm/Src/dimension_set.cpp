// Source for AP210 application object
//     dimension_set

// Precompiled include files
#include <StdAfx.h>

#include "dimension_set.h"

// Classes

dimension_set::dimension_set() {
   initialize();
   }
dimension_set::~dimension_set() {
   // Free string attributes
   }
// intialize data members
void dimension_set::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int dimension_set::DynamicType(int ID) {
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
dimension_set *dimension_set::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimension_set *>(s);
      }
   return NULL;
   }
dimension_set *dimension_set::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimension_set *>(s);
      }
   return NULL;
   }
// construction factory
dimension_set *dimension_set::Construct() {
   dimension_set *result = NULL;

   // create the dimension_set.
   result = new dimension_set();
   return result;
   }
bool dimension_set::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimension_set\r\n");

   // Check for the existence of all required attributes
   if (_associated_dimensions == NULL) {
      TRACE("ERROR: _associated_dimensions a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
