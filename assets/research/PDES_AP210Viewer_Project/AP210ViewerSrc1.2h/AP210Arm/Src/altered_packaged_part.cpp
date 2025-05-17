// Source for AP210 application object
//     altered_packaged_part

// Precompiled include files
#include <StdAfx.h>

#include "altered_packaged_part.h"

// Classes
#include <packaged_part.h>

altered_packaged_part::altered_packaged_part() {
   initialize();
   }
altered_packaged_part::~altered_packaged_part() {
   // Free string attributes
   }
// intialize data members
void altered_packaged_part::initialize() {
   // Required attributes
   _base_packaged_part = NULL;

   // Optional attributes
   }
// Runtime type identification
int altered_packaged_part::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = packaged_part::DynamicType(ID);
      }
   return result;
   }
altered_packaged_part *altered_packaged_part::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<altered_packaged_part *>(s);
      }
   return NULL;
   }
altered_packaged_part *altered_packaged_part::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<altered_packaged_part *>(s);
      }
   return NULL;
   }
// construction factory
altered_packaged_part *altered_packaged_part::Construct() {
   altered_packaged_part *result = NULL;

   // create the altered_packaged_part.
   result = new altered_packaged_part();
   return result;
   }
bool altered_packaged_part::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: altered_packaged_part\r\n");

   // Check for the existence of all required attributes
   if (_base_packaged_part == NULL) {
      TRACE("ERROR: _base_packaged_part a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (packaged_part::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
