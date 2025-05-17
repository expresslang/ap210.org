// Source for AP210 application object
//     component_based_annotation_symbol_placement_relationship

// Precompiled include files
#include <StdAfx.h>

#include "component_based_annotation_symbol_placement_relationship.h"

// Classes

component_based_annotation_symbol_placement_relationship::component_based_annotation_symbol_placement_relationship() {
   initialize();
   }
component_based_annotation_symbol_placement_relationship::~component_based_annotation_symbol_placement_relationship() {
   // Free string attributes
   }
// intialize data members
void component_based_annotation_symbol_placement_relationship::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int component_based_annotation_symbol_placement_relationship::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = component_feature_to_layout_feature_relationship::DynamicType(ID);
      }
   return result;
   }
component_based_annotation_symbol_placement_relationship *component_based_annotation_symbol_placement_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_based_annotation_symbol_placement_relationship *>(s);
      }
   return NULL;
   }
component_based_annotation_symbol_placement_relationship *component_based_annotation_symbol_placement_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_based_annotation_symbol_placement_relationship *>(s);
      }
   return NULL;
   }
// construction factory
component_based_annotation_symbol_placement_relationship *component_based_annotation_symbol_placement_relationship::Construct() {
   component_based_annotation_symbol_placement_relationship *result = NULL;

   // create the component_based_annotation_symbol_placement_relationship.
   result = new component_based_annotation_symbol_placement_relationship();
   return result;
   }
bool component_based_annotation_symbol_placement_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_based_annotation_symbol_placement_relationship\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (component_feature_to_layout_feature_relationship::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
