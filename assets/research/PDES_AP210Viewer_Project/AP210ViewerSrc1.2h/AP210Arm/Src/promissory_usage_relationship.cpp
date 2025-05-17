// Source for AP210 application object
//     promissory_usage_relationship

// Precompiled include files
#include <StdAfx.h>

#include "promissory_usage_relationship.h"

// Classes
#include <physical_unit.h>
#include <security_classification.h>
#include <physical_unit_design_view.h>

promissory_usage_relationship::promissory_usage_relationship() {
   initialize();
   }
promissory_usage_relationship::~promissory_usage_relationship() {
   // Free string attributes
   }
// intialize data members
void promissory_usage_relationship::initialize() {
   // Required attributes
   _component = NULL;
   _security_code = NULL;
   _assembly = NULL;

   // Optional attributes
   }
// Runtime type identification
int promissory_usage_relationship::DynamicType(int ID) {
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
promissory_usage_relationship *promissory_usage_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<promissory_usage_relationship *>(s);
      }
   return NULL;
   }
promissory_usage_relationship *promissory_usage_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<promissory_usage_relationship *>(s);
      }
   return NULL;
   }
// construction factory
promissory_usage_relationship *promissory_usage_relationship::Construct() {
   promissory_usage_relationship *result = NULL;

   // create the promissory_usage_relationship.
   result = new promissory_usage_relationship();
   return result;
   }
bool promissory_usage_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: promissory_usage_relationship\r\n");

   // Check for the existence of all required attributes
   if (_component == NULL) {
      TRACE("ERROR: _component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_security_code == NULL) {
      TRACE("ERROR: _security_code a required attribute is NULL!\r\n");
      result = false;
      }
   if (_assembly == NULL) {
      TRACE("ERROR: _assembly a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
