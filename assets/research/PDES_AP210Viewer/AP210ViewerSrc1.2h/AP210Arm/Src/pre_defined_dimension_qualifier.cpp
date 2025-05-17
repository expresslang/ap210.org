// Source for AP210 application object
//     pre_defined_dimension_qualifier

// Precompiled include files
#include <StdAfx.h>

#include "pre_defined_dimension_qualifier.h"

// Classes

pre_defined_dimension_qualifier::pre_defined_dimension_qualifier() {
   initialize();
   }
pre_defined_dimension_qualifier::~pre_defined_dimension_qualifier() {
   // Free string attributes
   }
// intialize data members
void pre_defined_dimension_qualifier::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int pre_defined_dimension_qualifier::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = dimension_qualifier::DynamicType(ID);
      }
   return result;
   }
pre_defined_dimension_qualifier *pre_defined_dimension_qualifier::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<pre_defined_dimension_qualifier *>(s);
      }
   return NULL;
   }
pre_defined_dimension_qualifier *pre_defined_dimension_qualifier::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<pre_defined_dimension_qualifier *>(s);
      }
   return NULL;
   }
// construction factory
pre_defined_dimension_qualifier *pre_defined_dimension_qualifier::Construct() {
   pre_defined_dimension_qualifier *result = NULL;

   // create the pre_defined_dimension_qualifier.
   result = new pre_defined_dimension_qualifier();
   return result;
   }
bool pre_defined_dimension_qualifier::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: pre_defined_dimension_qualifier\r\n");

   // Check for the existence of all required attributes
   if (_description == NULL) {
      TRACE("ERROR: _description a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (dimension_qualifier::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
