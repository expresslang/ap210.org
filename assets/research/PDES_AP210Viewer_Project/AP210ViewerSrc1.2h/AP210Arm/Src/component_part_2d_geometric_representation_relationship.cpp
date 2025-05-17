// Source for AP210 application object
//     component_part_2d_geometric_representation_relationship

// Precompiled include files
#include <StdAfx.h>

#include "component_part_2d_geometric_representation_relationship.h"

// Classes
#include <assembly_component_2d_shape.h>

component_part_2d_geometric_representation_relationship::component_part_2d_geometric_representation_relationship() {
   initialize();
   }
component_part_2d_geometric_representation_relationship::~component_part_2d_geometric_representation_relationship() {
   // Free string attributes
   }
// intialize data members
void component_part_2d_geometric_representation_relationship::initialize() {
   // Required attributes
   _component_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int component_part_2d_geometric_representation_relationship::DynamicType(int ID) {
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
component_part_2d_geometric_representation_relationship *component_part_2d_geometric_representation_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<component_part_2d_geometric_representation_relationship *>(s);
      }
   return NULL;
   }
component_part_2d_geometric_representation_relationship *component_part_2d_geometric_representation_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<component_part_2d_geometric_representation_relationship *>(s);
      }
   return NULL;
   }
// construction factory
component_part_2d_geometric_representation_relationship *component_part_2d_geometric_representation_relationship::Construct() {
   component_part_2d_geometric_representation_relationship *result = NULL;

   // create the component_part_2d_geometric_representation_relationship.
   result = new component_part_2d_geometric_representation_relationship();
   return result;
   }
bool component_part_2d_geometric_representation_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: component_part_2d_geometric_representation_relationship\r\n");

   // Check for the existence of all required attributes
   if (_part_shape == NULL) {
      TRACE("ERROR: _part_shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_component_shape == NULL) {
      TRACE("ERROR: _component_shape a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
