// Source for AP210 application object
//     sub_assembly_relationship

// Precompiled include files
#include <StdAfx.h>

#include "sub_assembly_relationship.h"

// Classes
#include <assembly_group_component.h>

sub_assembly_relationship::sub_assembly_relationship() {
   initialize();
   }
sub_assembly_relationship::~sub_assembly_relationship() {
   // Free string attributes
   }
// intialize data members
void sub_assembly_relationship::initialize() {
   // Required attributes
   _relating_component = NULL;

   // Optional attributes
   }
// Runtime type identification
int sub_assembly_relationship::DynamicType(int ID) {
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
sub_assembly_relationship *sub_assembly_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<sub_assembly_relationship *>(s);
      }
   return NULL;
   }
sub_assembly_relationship *sub_assembly_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<sub_assembly_relationship *>(s);
      }
   return NULL;
   }
// construction factory
sub_assembly_relationship *sub_assembly_relationship::Construct() {
   sub_assembly_relationship *result = NULL;

   // create the sub_assembly_relationship.
   result = new sub_assembly_relationship();
   return result;
   }
bool sub_assembly_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: sub_assembly_relationship\r\n");

   // Check for the existence of all required attributes
   if (_related_components == NULL) {
      TRACE("ERROR: _related_components a required attribute is NULL!\r\n");
      result = false;
      }
   if (_relating_component == NULL) {
      TRACE("ERROR: _relating_component a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
