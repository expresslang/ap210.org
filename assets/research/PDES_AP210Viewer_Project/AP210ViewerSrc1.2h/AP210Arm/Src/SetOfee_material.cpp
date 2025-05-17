// Source for AP210 application object
//     SetOfee_material

// Precompiled include files
#include <StdAfx.h>

#include "SetOfee_material.h"

// Classes
#include <ee_material.h>

SetOfee_material::SetOfee_material() {
   initialize();
   }
SetOfee_material::~SetOfee_material() {
   // Free string attributes
   }
// intialize data members
void SetOfee_material::initialize() {
   // Required attributes
   _ee_material = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfee_material::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfee_material *SetOfee_material::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfee_material *>(s);
      }
   return NULL;
   }
SetOfee_material *SetOfee_material::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfee_material *>(s);
      }
   return NULL;
   }
// construction factory
SetOfee_material *SetOfee_material::Construct() {
   SetOfee_material *result = NULL;

   // create the SetOfee_material.
   result = new SetOfee_material();
   return result;
   }
bool SetOfee_material::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfee_material\r\n");

   // Check for the existence of all required attributes
   if (_ee_material == NULL) {
      TRACE("ERROR: _ee_material a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
