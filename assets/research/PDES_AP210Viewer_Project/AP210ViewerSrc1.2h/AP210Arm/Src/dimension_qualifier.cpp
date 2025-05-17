// Source for AP210 application object
//     dimension_qualifier

// Precompiled include files
#include <StdAfx.h>

#include "dimension_qualifier.h"

// Classes

dimension_qualifier::dimension_qualifier() {
   initialize();
   }
dimension_qualifier::~dimension_qualifier() {
   // Free string attributes
   }
// intialize data members
void dimension_qualifier::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int dimension_qualifier::DynamicType(int ID) {
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
dimension_qualifier *dimension_qualifier::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimension_qualifier *>(s);
      }
   return NULL;
   }
dimension_qualifier *dimension_qualifier::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimension_qualifier *>(s);
      }
   return NULL;
   }
// construction factory
dimension_qualifier *dimension_qualifier::Construct() {
   dimension_qualifier *result = NULL;

   // create the dimension_qualifier.
   result = new dimension_qualifier();
   return result;
   }
bool dimension_qualifier::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimension_qualifier\r\n");

   // Check for the existence of all required attributes
   if (_qualified_dimensions == NULL) {
      TRACE("ERROR: _qualified_dimensions a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
