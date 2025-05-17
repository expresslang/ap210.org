// Source for AP210 application object
//     organization

// Precompiled include files
#include <StdAfx.h>

#include "organization.h"

// Classes

organization::organization() {
   initialize();
   }
organization::~organization() {
   // Free string attributes
   if (_identifier != NULL) {
      free(_identifier);
     }
   if (_Address != NULL) {
      free(_Address);
     }
   }
// intialize data members
void organization::initialize() {
   // Required attributes
   _identifier = NULL;

   // Optional attributes
   _Address = NULL;
   }
// Runtime type identification
int organization::DynamicType(int ID) {
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
organization *organization::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<organization *>(s);
      }
   return NULL;
   }
organization *organization::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<organization *>(s);
      }
   return NULL;
   }
// construction factory
organization *organization::Construct() {
   organization *result = NULL;

   // create the organization.
   result = new organization();
   return result;
   }
bool organization::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: organization\r\n");

   // Check for the existence of all required attributes
   if (_identifier == NULL) {
      TRACE("ERROR: _identifier a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
