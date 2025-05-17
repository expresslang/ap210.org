// Source for AP210 application object
//     frozen_assignment

// Precompiled include files
#include <StdAfx.h>

#include "frozen_assignment.h"

// Classes
#include <ee_approval.h>

frozen_assignment::frozen_assignment() {
   initialize();
   }
frozen_assignment::~frozen_assignment() {
   // Free string attributes
   }
// intialize data members
void frozen_assignment::initialize() {
   // Required attributes
   _assigned_approval = NULL;

   // Optional attributes
   }
// Runtime type identification
int frozen_assignment::DynamicType(int ID) {
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
frozen_assignment *frozen_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<frozen_assignment *>(s);
      }
   return NULL;
   }
frozen_assignment *frozen_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<frozen_assignment *>(s);
      }
   return NULL;
   }
// construction factory
frozen_assignment *frozen_assignment::Construct() {
   frozen_assignment *result = NULL;

   // create the frozen_assignment.
   result = new frozen_assignment();
   return result;
   }
bool frozen_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: frozen_assignment\r\n");

   // Check for the existence of all required attributes
   if (_frozen_item == NULL) {
      TRACE("ERROR: _frozen_item a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_approval == NULL) {
      TRACE("ERROR: _assigned_approval a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
