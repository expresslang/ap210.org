// Source for AP210 application object
//     physical_connectivity_interrupting_cutout

// Precompiled include files
#include <StdAfx.h>

#include "physical_connectivity_interrupting_cutout.h"

// Classes

physical_connectivity_interrupting_cutout::physical_connectivity_interrupting_cutout() {
   initialize();
   }
physical_connectivity_interrupting_cutout::~physical_connectivity_interrupting_cutout() {
   // Free string attributes
   }
// intialize data members
void physical_connectivity_interrupting_cutout::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int physical_connectivity_interrupting_cutout::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = cutout::DynamicType(ID);
      }
   return result;
   }
physical_connectivity_interrupting_cutout *physical_connectivity_interrupting_cutout::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<physical_connectivity_interrupting_cutout *>(s);
      }
   return NULL;
   }
physical_connectivity_interrupting_cutout *physical_connectivity_interrupting_cutout::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<physical_connectivity_interrupting_cutout *>(s);
      }
   return NULL;
   }
// construction factory
physical_connectivity_interrupting_cutout *physical_connectivity_interrupting_cutout::Construct() {
   physical_connectivity_interrupting_cutout *result = NULL;

   // create the physical_connectivity_interrupting_cutout.
   result = new physical_connectivity_interrupting_cutout();
   return result;
   }
bool physical_connectivity_interrupting_cutout::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: physical_connectivity_interrupting_cutout\r\n");

   // Check for the existence of all required attributes
   if (_interrupted_connectivity_element == NULL) {
      TRACE("ERROR: _interrupted_connectivity_element a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (cutout::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
