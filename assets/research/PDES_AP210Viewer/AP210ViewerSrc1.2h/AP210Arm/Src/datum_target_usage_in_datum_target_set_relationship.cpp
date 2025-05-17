// Source for AP210 application object
//     datum_target_usage_in_datum_target_set_relationship

// Precompiled include files
#include <StdAfx.h>

#include "datum_target_usage_in_datum_target_set_relationship.h"

// Classes
#include <datum_target_set.h>
#include <datum_target.h>

datum_target_usage_in_datum_target_set_relationship::datum_target_usage_in_datum_target_set_relationship() {
   initialize();
   }
datum_target_usage_in_datum_target_set_relationship::~datum_target_usage_in_datum_target_set_relationship() {
   // Free string attributes
   }
// intialize data members
void datum_target_usage_in_datum_target_set_relationship::initialize() {
   // Required attributes
   _defined_datum_target_set = NULL;
   _used_datum_target = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_target_usage_in_datum_target_set_relationship::DynamicType(int ID) {
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
datum_target_usage_in_datum_target_set_relationship *datum_target_usage_in_datum_target_set_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_target_usage_in_datum_target_set_relationship *>(s);
      }
   return NULL;
   }
datum_target_usage_in_datum_target_set_relationship *datum_target_usage_in_datum_target_set_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_target_usage_in_datum_target_set_relationship *>(s);
      }
   return NULL;
   }
// construction factory
datum_target_usage_in_datum_target_set_relationship *datum_target_usage_in_datum_target_set_relationship::Construct() {
   datum_target_usage_in_datum_target_set_relationship *result = NULL;

   // create the datum_target_usage_in_datum_target_set_relationship.
   result = new datum_target_usage_in_datum_target_set_relationship();
   return result;
   }
bool datum_target_usage_in_datum_target_set_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_target_usage_in_datum_target_set_relationship\r\n");

   // Check for the existence of all required attributes
   if (_defined_datum_target_set == NULL) {
      TRACE("ERROR: _defined_datum_target_set a required attribute is NULL!\r\n");
      result = false;
      }
   if (_used_datum_target == NULL) {
      TRACE("ERROR: _used_datum_target a required attribute is NULL!\r\n");
      result = false;
      }
   if (_datum_target_number == NULL) {
      TRACE("ERROR: _datum_target_number a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
