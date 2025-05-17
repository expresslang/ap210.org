// Source for AP210 application object
//     component_termination_passage_template

// Precompiled include files
#include <StdAfx.h>

#include "component_termination_passage_template.h"

// Classes

component_termination_passage_template::component_termination_passage_template() {
   initialize();
   }
component_termination_passage_template::~component_termination_passage_template() {
   // Free string attributes
   }
// intialize data members
void component_termination_passage_template::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int component_termination_passage_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = inter_stratum_feature_template::DynamicType(ID);
      }
   return result;
   }
component_termination_passage_template *component_termination_passage_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_termination_passage_template *>(s);
      }
   return NULL;
   }
component_termination_passage_template *component_termination_passage_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_termination_passage_template *>(s);
      }
   return NULL;
   }
// construction factory
component_termination_passage_template *component_termination_passage_template::Construct() {
   component_termination_passage_template *result = NULL;

   // create the component_termination_passage_template.
   result = new component_termination_passage_template();
   return result;
   }
bool component_termination_passage_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_termination_passage_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (inter_stratum_feature_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
