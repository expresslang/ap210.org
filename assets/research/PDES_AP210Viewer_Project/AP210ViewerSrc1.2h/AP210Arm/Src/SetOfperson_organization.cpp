// Source for AP210 application object
//     SetOfperson_organization

// Precompiled include files
#include <StdAfx.h>

#include "SetOfperson_organization.h"

// Classes

SetOfperson_organization::SetOfperson_organization() {
   initialize();
   }
SetOfperson_organization::~SetOfperson_organization() {
   // Free string attributes
   }
// intialize data members
void SetOfperson_organization::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOfperson_organization::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfperson_organization *SetOfperson_organization::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfperson_organization *>(s);
      }
   return NULL;
   }
SetOfperson_organization *SetOfperson_organization::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfperson_organization *>(s);
      }
   return NULL;
   }
// construction factory
SetOfperson_organization *SetOfperson_organization::Construct() {
   SetOfperson_organization *result = NULL;

   // create the SetOfperson_organization.
   result = new SetOfperson_organization();
   return result;
   }
bool SetOfperson_organization::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfperson_organization\r\n");

   // Check for the existence of all required attributes
   if (_person_organization == NULL) {
      TRACE("ERROR: _person_organization a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
