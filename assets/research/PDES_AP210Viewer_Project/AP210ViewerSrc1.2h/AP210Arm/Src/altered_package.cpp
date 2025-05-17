// Source for AP210 application object
//     altered_package

// Precompiled include files
#include <StdAfx.h>

#include "altered_package.h"

// Classes
#include <package.h>

altered_package::altered_package() {
   initialize();
   }
altered_package::~altered_package() {
   // Free string attributes
   }
// intialize data members
void altered_package::initialize() {
   // Required attributes
   _package_to_be_altered = NULL;

   // Optional attributes
   }
// Runtime type identification
int altered_package::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = package::DynamicType(ID);
      }
   return result;
   }
altered_package *altered_package::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<altered_package *>(s);
      }
   return NULL;
   }
altered_package *altered_package::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<altered_package *>(s);
      }
   return NULL;
   }
// construction factory
altered_package *altered_package::Construct() {
   altered_package *result = NULL;

   // create the altered_package.
   result = new altered_package();
   return result;
   }
bool altered_package::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: altered_package\r\n");

   // Check for the existence of all required attributes
   if (_package_to_be_altered == NULL) {
      TRACE("ERROR: _package_to_be_altered a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (package::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
