// Source for AP210 application object
//     operational_requirement_occurrence_relationship

// Precompiled include files
#include <StdAfx.h>

#include "operational_requirement_occurrence_relationship.h"

// Classes
#include <ee_requirement_occurrence.h>
#include <ee_requirement_occurrence.h>

operational_requirement_occurrence_relationship::operational_requirement_occurrence_relationship() {
   initialize();
   }
operational_requirement_occurrence_relationship::~operational_requirement_occurrence_relationship() {
   // Free string attributes
   }
// intialize data members
void operational_requirement_occurrence_relationship::initialize() {
   // Required attributes
   _relating_requirement_occurrence = NULL;
   _related_requirement_occurrence = NULL;

   // Optional attributes
   }
// Runtime type identification
int operational_requirement_occurrence_relationship::DynamicType(int ID) {
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
operational_requirement_occurrence_relationship *operational_requirement_occurrence_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<operational_requirement_occurrence_relationship *>(s);
      }
   return NULL;
   }
operational_requirement_occurrence_relationship *operational_requirement_occurrence_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<operational_requirement_occurrence_relationship *>(s);
      }
   return NULL;
   }
// construction factory
operational_requirement_occurrence_relationship *operational_requirement_occurrence_relationship::Construct() {
   operational_requirement_occurrence_relationship *result = NULL;

   // create the operational_requirement_occurrence_relationship.
   result = new operational_requirement_occurrence_relationship();
   return result;
   }
bool operational_requirement_occurrence_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: operational_requirement_occurrence_relationship\r\n");

   // Check for the existence of all required attributes
   if (_relationship_type == NULL) {
      TRACE("ERROR: _relationship_type a required attribute is NULL!\r\n");
      result = false;
      }
   if (_relating_requirement_occurrence == NULL) {
      TRACE("ERROR: _relating_requirement_occurrence a required attribute is NULL!\r\n");
      result = false;
      }
   if (_related_requirement_occurrence == NULL) {
      TRACE("ERROR: _related_requirement_occurrence a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
