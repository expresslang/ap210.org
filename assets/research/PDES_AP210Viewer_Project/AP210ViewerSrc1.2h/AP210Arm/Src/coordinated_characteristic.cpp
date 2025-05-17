// Source for AP210 application object
//     coordinated_characteristic

// Precompiled include files
#include <StdAfx.h>

#include "coordinated_characteristic.h"

// Classes

coordinated_characteristic::coordinated_characteristic() {
   initialize();
   }
coordinated_characteristic::~coordinated_characteristic() {
   // Free string attributes
   if (_type_name != NULL) {
      free(_type_name);
     }
   if (_dependent_environment != NULL) {
      free(_dependent_environment);
     }
   }
// intialize data members
void coordinated_characteristic::initialize() {
   // Required attributes
   _type_name = NULL;

   // Optional attributes
   _dependent_environment = NULL;
   }
// Runtime type identification
int coordinated_characteristic::DynamicType(int ID) {
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
coordinated_characteristic *coordinated_characteristic::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<coordinated_characteristic *>(s);
      }
   return NULL;
   }
coordinated_characteristic *coordinated_characteristic::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<coordinated_characteristic *>(s);
      }
   return NULL;
   }
// construction factory
coordinated_characteristic *coordinated_characteristic::Construct() {
   coordinated_characteristic *result = NULL;

   // create the coordinated_characteristic.
   result = new coordinated_characteristic();
   return result;
   }
bool coordinated_characteristic::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: coordinated_characteristic\r\n");

   // Check for the existence of all required attributes
   if (_type_name == NULL) {
      TRACE("ERROR: _type_name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_component_characteristic == NULL) {
      TRACE("ERROR: _component_characteristic a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_document == NULL) {
      TRACE("ERROR: _reference_document a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
