// Source for AP210 application object
//     component_termination_passage_dependent_land

// Precompiled include files
#include <StdAfx.h>

#include "component_termination_passage_dependent_land.h"

// Classes
#include <component_termination_passage.h>

component_termination_passage_dependent_land::component_termination_passage_dependent_land() {
   initialize();
   }
component_termination_passage_dependent_land::~component_termination_passage_dependent_land() {
   // Free string attributes
   }
// intialize data members
void component_termination_passage_dependent_land::initialize() {
   // Required attributes
   _reference_passage = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_termination_passage_dependent_land::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = land::DynamicType(ID);
      }
   return result;
   }
component_termination_passage_dependent_land *component_termination_passage_dependent_land::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_termination_passage_dependent_land *>(s);
      }
   return NULL;
   }
component_termination_passage_dependent_land *component_termination_passage_dependent_land::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_termination_passage_dependent_land *>(s);
      }
   return NULL;
   }
// construction factory
component_termination_passage_dependent_land *component_termination_passage_dependent_land::Construct() {
   component_termination_passage_dependent_land *result = NULL;

   // create the component_termination_passage_dependent_land.
   result = new component_termination_passage_dependent_land();
   return result;
   }
bool component_termination_passage_dependent_land::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_termination_passage_dependent_land\r\n");

   // Check for the existence of all required attributes
   if (_reference_passage == NULL) {
      TRACE("ERROR: _reference_passage a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (land::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
