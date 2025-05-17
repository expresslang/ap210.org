// Source for AP210 application object
//     assembly_module_usage_view_connector_relationship

// Precompiled include files
#include <StdAfx.h>

#include "assembly_module_usage_view_connector_relationship.h"

// Classes

assembly_module_usage_view_connector_relationship::assembly_module_usage_view_connector_relationship() {
   initialize();
   }
assembly_module_usage_view_connector_relationship::~assembly_module_usage_view_connector_relationship() {
   // Free string attributes
   if (_externally_visible_partial_reference_designation != NULL) {
      free(_externally_visible_partial_reference_designation);
     }
   }
// intialize data members
void assembly_module_usage_view_connector_relationship::initialize() {
   // Required attributes
   _externally_visible_partial_reference_designation = NULL;

   // Optional attributes
   }
// Runtime type identification
int assembly_module_usage_view_connector_relationship::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = usage_concept_usage_relationship::DynamicType(ID);
      }
   return result;
   }
assembly_module_usage_view_connector_relationship *assembly_module_usage_view_connector_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<assembly_module_usage_view_connector_relationship *>(s);
      }
   return NULL;
   }
assembly_module_usage_view_connector_relationship *assembly_module_usage_view_connector_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<assembly_module_usage_view_connector_relationship *>(s);
      }
   return NULL;
   }
// construction factory
assembly_module_usage_view_connector_relationship *assembly_module_usage_view_connector_relationship::Construct() {
   assembly_module_usage_view_connector_relationship *result = NULL;

   // create the assembly_module_usage_view_connector_relationship.
   result = new assembly_module_usage_view_connector_relationship();
   return result;
   }
bool assembly_module_usage_view_connector_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: assembly_module_usage_view_connector_relationship\r\n");

   // Check for the existence of all required attributes
   if (_externally_visible_partial_reference_designation == NULL) {
      TRACE("ERROR: _externally_visible_partial_reference_designation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (usage_concept_usage_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
