// Source for AP210 application object
//     dimension_related_positional_boundary

// Precompiled include files
#include <StdAfx.h>

#include "dimension_related_positional_boundary.h"

// Classes
#include <physical_feature_or_part_template.h>

dimension_related_positional_boundary::dimension_related_positional_boundary() {
   initialize();
   }
dimension_related_positional_boundary::~dimension_related_positional_boundary() {
   // Free string attributes
   }
// intialize data members
void dimension_related_positional_boundary::initialize() {
   // Required attributes
   _constrained_physical_feature = NULL;

   // Optional attributes
   }
// Runtime type identification
int dimension_related_positional_boundary::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = positional_boundary::DynamicType(ID);
      }
   return result;
   }
dimension_related_positional_boundary *dimension_related_positional_boundary::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<dimension_related_positional_boundary *>(s);
      }
   return NULL;
   }
dimension_related_positional_boundary *dimension_related_positional_boundary::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<dimension_related_positional_boundary *>(s);
      }
   return NULL;
   }
// construction factory
dimension_related_positional_boundary *dimension_related_positional_boundary::Construct() {
   dimension_related_positional_boundary *result = NULL;

   // create the dimension_related_positional_boundary.
   result = new dimension_related_positional_boundary();
   return result;
   }
bool dimension_related_positional_boundary::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: dimension_related_positional_boundary\r\n");

   // Check for the existence of all required attributes
   if (_boundary_members == NULL) {
      TRACE("ERROR: _boundary_members a required attribute is NULL!\r\n");
      result = false;
      }
   if (_constrained_physical_feature == NULL) {
      TRACE("ERROR: _constrained_physical_feature a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (positional_boundary::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
