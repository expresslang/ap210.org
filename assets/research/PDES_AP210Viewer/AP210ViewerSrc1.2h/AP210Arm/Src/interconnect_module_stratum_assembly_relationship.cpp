// Source for AP210 application object
//     interconnect_module_stratum_assembly_relationship

// Precompiled include files
#include <StdAfx.h>

#include "interconnect_module_stratum_assembly_relationship.h"

// Classes
#include <interconnect_module.h>
#include <stratum.h>

interconnect_module_stratum_assembly_relationship::interconnect_module_stratum_assembly_relationship() {
   initialize();
   }
interconnect_module_stratum_assembly_relationship::~interconnect_module_stratum_assembly_relationship() {
   // Free string attributes
   if (_reference_designation != NULL) {
      free(_reference_designation);
     }
   }
// intialize data members
void interconnect_module_stratum_assembly_relationship::initialize() {
   // Required attributes
   _assembly = NULL;
   _component = NULL;
   _reference_designation = NULL;

   // Optional attributes
   }
// Runtime type identification
int interconnect_module_stratum_assembly_relationship::DynamicType(int ID) {
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
interconnect_module_stratum_assembly_relationship *interconnect_module_stratum_assembly_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<interconnect_module_stratum_assembly_relationship *>(s);
      }
   return NULL;
   }
interconnect_module_stratum_assembly_relationship *interconnect_module_stratum_assembly_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<interconnect_module_stratum_assembly_relationship *>(s);
      }
   return NULL;
   }
// construction factory
interconnect_module_stratum_assembly_relationship *interconnect_module_stratum_assembly_relationship::Construct() {
   interconnect_module_stratum_assembly_relationship *result = NULL;

   // create the interconnect_module_stratum_assembly_relationship.
   result = new interconnect_module_stratum_assembly_relationship();
   return result;
   }
bool interconnect_module_stratum_assembly_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: interconnect_module_stratum_assembly_relationship\r\n");

   // Check for the existence of all required attributes
   if (_assembly == NULL) {
      TRACE("ERROR: _assembly a required attribute is NULL!\r\n");
      result = false;
      }
   if (_component == NULL) {
      TRACE("ERROR: _component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_designation == NULL) {
      TRACE("ERROR: _reference_designation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
