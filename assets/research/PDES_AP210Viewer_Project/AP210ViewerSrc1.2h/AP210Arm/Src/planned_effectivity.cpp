// Source for AP210 application object
//     planned_effectivity

// Precompiled include files
#include <StdAfx.h>

#include "planned_effectivity.h"

// Classes
#include <assembly_composition_relationship.h>
#include <ee_approval.h>
#include <ee_product_configuration.h>
#include <data_element.h>

planned_effectivity::planned_effectivity() {
   initialize();
   }
planned_effectivity::~planned_effectivity() {
   // Free string attributes
   }
// intialize data members
void planned_effectivity::initialize() {
   // Required attributes
   _effective_assembly = NULL;
   _effectivity_approval = NULL;
   _configuration = NULL;

   // Optional attributes
   _component_quantity = NULL;
   }
// Runtime type identification
int planned_effectivity::DynamicType(int ID) {
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
planned_effectivity *planned_effectivity::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<planned_effectivity *>(s);
      }
   return NULL;
   }
planned_effectivity *planned_effectivity::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<planned_effectivity *>(s);
      }
   return NULL;
   }
// construction factory
planned_effectivity *planned_effectivity::Construct() {
   planned_effectivity *result = NULL;

   // create the planned_effectivity.
   result = new planned_effectivity();
   return result;
   }
bool planned_effectivity::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: planned_effectivity\r\n");

   // Check for the existence of all required attributes
   if (_effective_assembly == NULL) {
      TRACE("ERROR: _effective_assembly a required attribute is NULL!\r\n");
      result = false;
      }
   if (_effectivity_approval == NULL) {
      TRACE("ERROR: _effectivity_approval a required attribute is NULL!\r\n");
      result = false;
      }
   if (_configuration == NULL) {
      TRACE("ERROR: _configuration a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
