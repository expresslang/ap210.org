// Source for AP210 application object
//     usage_concept_usage_relationship

// Precompiled include files
#include <StdAfx.h>

#include "usage_concept_usage_relationship.h"

// Classes
#include <axis_placement.h>

usage_concept_usage_relationship::usage_concept_usage_relationship() {
   initialize();
   }
usage_concept_usage_relationship::~usage_concept_usage_relationship() {
   // Free string attributes
   }
// intialize data members
void usage_concept_usage_relationship::initialize() {
   // Required attributes
   _associated_usage_placement = NULL;

   // Optional attributes
   }
// Runtime type identification
int usage_concept_usage_relationship::DynamicType(int ID) {
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
usage_concept_usage_relationship *usage_concept_usage_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<usage_concept_usage_relationship *>(s);
      }
   return NULL;
   }
usage_concept_usage_relationship *usage_concept_usage_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<usage_concept_usage_relationship *>(s);
      }
   return NULL;
   }
// construction factory
usage_concept_usage_relationship *usage_concept_usage_relationship::Construct() {
   usage_concept_usage_relationship *result = NULL;

   // create the usage_concept_usage_relationship.
   result = new usage_concept_usage_relationship();
   return result;
   }
bool usage_concept_usage_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: usage_concept_usage_relationship\r\n");

   // Check for the existence of all required attributes
   if (_associating_usage == NULL) {
      TRACE("ERROR: _associating_usage a required attribute is NULL!\r\n");
      result = false;
      }
   if (_associated_usage == NULL) {
      TRACE("ERROR: _associated_usage a required attribute is NULL!\r\n");
      result = false;
      }
   if (_associated_usage_placement == NULL) {
      TRACE("ERROR: _associated_usage_placement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
