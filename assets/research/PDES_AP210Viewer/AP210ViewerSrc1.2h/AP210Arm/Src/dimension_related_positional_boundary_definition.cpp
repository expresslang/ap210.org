// Source for AP210 application object
//     dimension_related_positional_boundary_definition

// Precompiled include files
#include <StdAfx.h>

#include "dimension_related_positional_boundary_definition.h"

// Classes

dimension_related_positional_boundary_definition::dimension_related_positional_boundary_definition() {
   initialize();
   }
dimension_related_positional_boundary_definition::~dimension_related_positional_boundary_definition() {
   // Free string attributes
   }
// intialize data members
void dimension_related_positional_boundary_definition::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int dimension_related_positional_boundary_definition::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = positional_boundary_definition::DynamicType(ID);
      }
   return result;
   }
dimension_related_positional_boundary_definition *dimension_related_positional_boundary_definition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimension_related_positional_boundary_definition *>(s);
      }
   return NULL;
   }
dimension_related_positional_boundary_definition *dimension_related_positional_boundary_definition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimension_related_positional_boundary_definition *>(s);
      }
   return NULL;
   }
// construction factory
dimension_related_positional_boundary_definition *dimension_related_positional_boundary_definition::Construct() {
   dimension_related_positional_boundary_definition *result = NULL;

   // create the dimension_related_positional_boundary_definition.
   result = new dimension_related_positional_boundary_definition();
   return result;
   }
bool dimension_related_positional_boundary_definition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimension_related_positional_boundary_definition\r\n");

   // Check for the existence of all required attributes
   if (_characterized_boundary_member_definitions == NULL) {
      TRACE("ERROR: _characterized_boundary_member_definitions a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (positional_boundary_definition::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
