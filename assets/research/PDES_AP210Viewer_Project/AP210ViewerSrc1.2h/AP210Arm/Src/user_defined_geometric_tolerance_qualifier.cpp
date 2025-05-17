// Source for AP210 application object
//     user_defined_geometric_tolerance_qualifier

// Precompiled include files
#include <StdAfx.h>

#include "user_defined_geometric_tolerance_qualifier.h"

// Classes

user_defined_geometric_tolerance_qualifier::user_defined_geometric_tolerance_qualifier() {
   initialize();
   }
user_defined_geometric_tolerance_qualifier::~user_defined_geometric_tolerance_qualifier() {
   // Free string attributes
   if (_description != NULL) {
      free(_description);
     }
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void user_defined_geometric_tolerance_qualifier::initialize() {
   // Required attributes
   _description = NULL;
   _name = NULL;

   // Optional attributes
   }
// Runtime type identification
int user_defined_geometric_tolerance_qualifier::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = geometric_tolerance_qualifier::DynamicType(ID);
      }
   return result;
   }
user_defined_geometric_tolerance_qualifier *user_defined_geometric_tolerance_qualifier::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<user_defined_geometric_tolerance_qualifier *>(s);
      }
   return NULL;
   }
user_defined_geometric_tolerance_qualifier *user_defined_geometric_tolerance_qualifier::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<user_defined_geometric_tolerance_qualifier *>(s);
      }
   return NULL;
   }
// construction factory
user_defined_geometric_tolerance_qualifier *user_defined_geometric_tolerance_qualifier::Construct() {
   user_defined_geometric_tolerance_qualifier *result = NULL;

   // create the user_defined_geometric_tolerance_qualifier.
   result = new user_defined_geometric_tolerance_qualifier();
   return result;
   }
bool user_defined_geometric_tolerance_qualifier::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: user_defined_geometric_tolerance_qualifier\r\n");

   // Check for the existence of all required attributes
   if (_description == NULL) {
      TRACE("ERROR: _description a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (geometric_tolerance_qualifier::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
