// Source for AP210 application object
//     via_dependent_land

// Precompiled include files
#include <StdAfx.h>

#include "via_dependent_land.h"

// Classes
#include <via.h>

via_dependent_land::via_dependent_land() {
   initialize();
   }
via_dependent_land::~via_dependent_land() {
   // Free string attributes
   }
// intialize data members
void via_dependent_land::initialize() {
   // Required attributes
   _reference_via = NULL;

   // Optional attributes
   }
// Runtime type identification
int via_dependent_land::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = land::DynamicType(ID);
      }
   return result;
   }
via_dependent_land *via_dependent_land::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<via_dependent_land *>(s);
      }
   return NULL;
   }
via_dependent_land *via_dependent_land::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<via_dependent_land *>(s);
      }
   return NULL;
   }
// construction factory
via_dependent_land *via_dependent_land::Construct() {
   via_dependent_land *result = NULL;

   // create the via_dependent_land.
   result = new via_dependent_land();
   return result;
   }
bool via_dependent_land::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: via_dependent_land\r\n");

   // Check for the existence of all required attributes
   if (_reference_via == NULL) {
      TRACE("ERROR: _reference_via a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (land::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
