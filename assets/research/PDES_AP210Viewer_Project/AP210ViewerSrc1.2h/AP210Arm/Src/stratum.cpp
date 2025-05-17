// Source for AP210 application object
//     stratum

// Precompiled include files
#include <StdAfx.h>

#include "stratum.h"

// Classes
#include <external_definition.h>
#include <stratum_technology.h>

stratum::stratum() {
   initialize();
   }
stratum::~stratum() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void stratum::initialize() {
   // Required attributes
   _name = NULL;
   _of_technology = NULL;

   // Optional attributes
   _stratum_usage = NULL;
   }
// Runtime type identification
int stratum::DynamicType(int ID) {
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
stratum *stratum::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum *>(s);
      }
   return NULL;
   }
stratum *stratum::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum *>(s);
      }
   return NULL;
   }
// construction factory
stratum *stratum::Construct() {
   stratum *result = NULL;

   // create the stratum.
   result = new stratum();
   return result;
   }
bool stratum::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum\r\n");

   // Check for the existence of all required attributes
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_of_technology == NULL) {
      TRACE("ERROR: _of_technology a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
