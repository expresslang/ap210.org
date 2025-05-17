// Source for AP210 application object
//     fabrication_joint

// Precompiled include files
#include <StdAfx.h>

#include "fabrication_joint.h"

// Classes
#include <stratum_feature_template_component.h>

fabrication_joint::fabrication_joint() {
   initialize();
   }
fabrication_joint::~fabrication_joint() {
   // Free string attributes
   }
// intialize data members
void fabrication_joint::initialize() {
   // Required attributes

   // Optional attributes
   _auxiliary_joint_material = NULL;
   }
// Runtime type identification
int fabrication_joint::DynamicType(int ID) {
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
fabrication_joint *fabrication_joint::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fabrication_joint *>(s);
      }
   return NULL;
   }
fabrication_joint *fabrication_joint::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fabrication_joint *>(s);
      }
   return NULL;
   }
// construction factory
fabrication_joint *fabrication_joint::Construct() {
   fabrication_joint *result = NULL;

   // create the fabrication_joint.
   result = new fabrication_joint();
   return result;
   }
bool fabrication_joint::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fabrication_joint\r\n");

   // Check for the existence of all required attributes
   if (_fabrication_features == NULL) {
      TRACE("ERROR: _fabrication_features a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
