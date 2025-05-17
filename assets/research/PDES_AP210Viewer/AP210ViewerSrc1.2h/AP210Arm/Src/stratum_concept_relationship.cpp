// Source for AP210 application object
//     stratum_concept_relationship

// Precompiled include files
#include <StdAfx.h>

#include "stratum_concept_relationship.h"

// Classes
#include <feature_shape_definition.h>

stratum_concept_relationship::stratum_concept_relationship() {
   initialize();
   }
stratum_concept_relationship::~stratum_concept_relationship() {
   // Free string attributes
   }
// intialize data members
void stratum_concept_relationship::initialize() {
   // Required attributes

   // Optional attributes
   _resulting_shape = NULL;
   }
// Runtime type identification
int stratum_concept_relationship::DynamicType(int ID) {
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
stratum_concept_relationship *stratum_concept_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_concept_relationship *>(s);
      }
   return NULL;
   }
stratum_concept_relationship *stratum_concept_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_concept_relationship *>(s);
      }
   return NULL;
   }
// construction factory
stratum_concept_relationship *stratum_concept_relationship::Construct() {
   stratum_concept_relationship *result = NULL;

   // create the stratum_concept_relationship.
   result = new stratum_concept_relationship();
   return result;
   }
bool stratum_concept_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_concept_relationship\r\n");

   // Check for the existence of all required attributes
   if (_technology_requirement == NULL) {
      TRACE("ERROR: _technology_requirement a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
