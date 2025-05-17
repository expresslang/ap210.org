// Source for AP210 application object
//     SetOfdesign_object_management_relationship_or_description

// Precompiled include files
#include <StdAfx.h>

#include "SetOfdesign_object_management_relationship_or_description.h"

// Classes

SetOfdesign_object_management_relationship_or_description::SetOfdesign_object_management_relationship_or_description() {
   initialize();
   }
SetOfdesign_object_management_relationship_or_description::~SetOfdesign_object_management_relationship_or_description() {
   // Free string attributes
   }
// intialize data members
void SetOfdesign_object_management_relationship_or_description::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int SetOfdesign_object_management_relationship_or_description::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfdesign_object_management_relationship_or_description *SetOfdesign_object_management_relationship_or_description::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfdesign_object_management_relationship_or_description *>(s);
      }
   return NULL;
   }
SetOfdesign_object_management_relationship_or_description *SetOfdesign_object_management_relationship_or_description::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfdesign_object_management_relationship_or_description *>(s);
      }
   return NULL;
   }
// construction factory
SetOfdesign_object_management_relationship_or_description *SetOfdesign_object_management_relationship_or_description::Construct() {
   SetOfdesign_object_management_relationship_or_description *result = NULL;

   // create the SetOfdesign_object_management_relationship_or_description.
   result = new SetOfdesign_object_management_relationship_or_description();
   return result;
   }
bool SetOfdesign_object_management_relationship_or_description::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfdesign_object_management_relationship_or_description\r\n");

   // Check for the existence of all required attributes
   if (_design_object_management_relationship_or_description == NULL) {
      TRACE("ERROR: _design_object_management_relationship_or_description a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
