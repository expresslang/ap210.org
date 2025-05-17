// Source for AP210 application object
//     true_profile

// Precompiled include files
#include <StdAfx.h>

#include "true_profile.h"

// Classes
#include <physical_feature_or_part_template.h>

true_profile::true_profile() {
   initialize();
   }
true_profile::~true_profile() {
   // Free string attributes
   }
// intialize data members
void true_profile::initialize() {
   // Required attributes
   _profiled_surface = NULL;

   // Optional attributes
   }
// Runtime type identification
int true_profile::DynamicType(int ID) {
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
true_profile *true_profile::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<true_profile *>(s);
      }
   return NULL;
   }
true_profile *true_profile::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<true_profile *>(s);
      }
   return NULL;
   }
// construction factory
true_profile *true_profile::Construct() {
   true_profile *result = NULL;

   // create the true_profile.
   result = new true_profile();
   return result;
   }
bool true_profile::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: true_profile\r\n");

   // Check for the existence of all required attributes
   if (_profiled_surface == NULL) {
      TRACE("ERROR: _profiled_surface a required attribute is NULL!\r\n");
      result = false;
      }
   if (_profile_representation == NULL) {
      TRACE("ERROR: _profile_representation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
