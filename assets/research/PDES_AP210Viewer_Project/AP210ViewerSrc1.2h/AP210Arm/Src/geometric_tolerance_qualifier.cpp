// Source for AP210 application object
//     geometric_tolerance_qualifier

// Precompiled include files
#include <StdAfx.h>

#include "geometric_tolerance_qualifier.h"

// Classes

geometric_tolerance_qualifier::geometric_tolerance_qualifier() {
   initialize();
   }
geometric_tolerance_qualifier::~geometric_tolerance_qualifier() {
   // Free string attributes
   }
// intialize data members
void geometric_tolerance_qualifier::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int geometric_tolerance_qualifier::DynamicType(int ID) {
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
geometric_tolerance_qualifier *geometric_tolerance_qualifier::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<geometric_tolerance_qualifier *>(s);
      }
   return NULL;
   }
geometric_tolerance_qualifier *geometric_tolerance_qualifier::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<geometric_tolerance_qualifier *>(s);
      }
   return NULL;
   }
// construction factory
geometric_tolerance_qualifier *geometric_tolerance_qualifier::Construct() {
   geometric_tolerance_qualifier *result = NULL;

   // create the geometric_tolerance_qualifier.
   result = new geometric_tolerance_qualifier();
   return result;
   }
bool geometric_tolerance_qualifier::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: geometric_tolerance_qualifier\r\n");

   // Check for the existence of all required attributes
   if (_qualified_geometric_tolerances == NULL) {
      TRACE("ERROR: _qualified_geometric_tolerances a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
