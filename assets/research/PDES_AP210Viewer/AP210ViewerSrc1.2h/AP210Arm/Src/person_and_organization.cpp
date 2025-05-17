// Source for AP210 application object
//     person_and_organization

// Precompiled include files
#include <StdAfx.h>

#include "person_and_organization.h"

// Classes
#include <person.h>
#include <organization.h>

person_and_organization::person_and_organization() {
   initialize();
   }
person_and_organization::~person_and_organization() {
   // Free string attributes
   }
// intialize data members
void person_and_organization::initialize() {
   // Required attributes
   _assigned_person = NULL;
   _assigned_organization = NULL;

   // Optional attributes
   }
// Runtime type identification
int person_and_organization::DynamicType(int ID) {
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
person_and_organization *person_and_organization::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<person_and_organization *>(s);
      }
   return NULL;
   }
person_and_organization *person_and_organization::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<person_and_organization *>(s);
      }
   return NULL;
   }
// construction factory
person_and_organization *person_and_organization::Construct() {
   person_and_organization *result = NULL;

   // create the person_and_organization.
   result = new person_and_organization();
   return result;
   }
bool person_and_organization::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: person_and_organization\r\n");

   // Check for the existence of all required attributes
   if (_assigned_person == NULL) {
      TRACE("ERROR: _assigned_person a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assigned_organization == NULL) {
      TRACE("ERROR: _assigned_organization a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
