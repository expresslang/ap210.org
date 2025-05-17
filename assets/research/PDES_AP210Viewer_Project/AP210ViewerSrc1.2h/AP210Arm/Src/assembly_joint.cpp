// Source for AP210 application object
//     assembly_joint

// Precompiled include files
#include <StdAfx.h>

#include "assembly_joint.h"

// Classes

assembly_joint::assembly_joint() {
   initialize();
   }
assembly_joint::~assembly_joint() {
   // Free string attributes
   if (_description != NULL) {
      free(_description);
     }
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void assembly_joint::initialize() {
   // Required attributes

   // Optional attributes
   _description = NULL;
   _name = NULL;
   }
// Runtime type identification
int assembly_joint::DynamicType(int ID) {
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
assembly_joint *assembly_joint::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_joint *>(s);
      }
   return NULL;
   }
assembly_joint *assembly_joint::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_joint *>(s);
      }
   return NULL;
   }
// construction factory
assembly_joint *assembly_joint::Construct() {
   assembly_joint *result = NULL;

   // create the assembly_joint.
   result = new assembly_joint();
   return result;
   }
bool assembly_joint::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_joint\r\n");

   // Check for the existence of all required attributes
   if (_assembly_features == NULL) {
      TRACE("ERROR: _assembly_features a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
