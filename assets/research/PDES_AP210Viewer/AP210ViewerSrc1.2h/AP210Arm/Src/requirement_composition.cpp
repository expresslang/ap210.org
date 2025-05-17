// Source for AP210 application object
//     requirement_composition

// Precompiled include files
#include <StdAfx.h>

#include "requirement_composition.h"

// Classes
#include <requirement_group_occurrence.h>

requirement_composition::requirement_composition() {
   initialize();
   }
requirement_composition::~requirement_composition() {
   // Free string attributes
   }
// intialize data members
void requirement_composition::initialize() {
   // Required attributes
   _composition = NULL;

   // Optional attributes
   }
// Runtime type identification
int requirement_composition::DynamicType(int ID) {
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
requirement_composition *requirement_composition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<requirement_composition *>(s);
      }
   return NULL;
   }
requirement_composition *requirement_composition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<requirement_composition *>(s);
      }
   return NULL;
   }
// construction factory
requirement_composition *requirement_composition::Construct() {
   requirement_composition *result = NULL;

   // create the requirement_composition.
   result = new requirement_composition();
   return result;
   }
bool requirement_composition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: requirement_composition\r\n");

   // Check for the existence of all required attributes
   if (_element == NULL) {
      TRACE("ERROR: _element a required attribute is NULL!\r\n");
      result = false;
      }
   if (_composition == NULL) {
      TRACE("ERROR: _composition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
