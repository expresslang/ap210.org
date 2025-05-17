// Source for AP210 application object
//     shape_element_relationship

// Precompiled include files
#include <StdAfx.h>

#include "shape_element_relationship.h"

// Classes
#include <shape_element.h>
#include <shape_element.h>

shape_element_relationship::shape_element_relationship() {
   initialize();
   }
shape_element_relationship::~shape_element_relationship() {
   // Free string attributes
   if (_description != NULL) {
      free(_description);
     }
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void shape_element_relationship::initialize() {
   // Required attributes
   _relating_shape_element = NULL;
   _related_shape_element = NULL;

   // Optional attributes
   _description = NULL;
   _name = NULL;
   }
// Runtime type identification
int shape_element_relationship::DynamicType(int ID) {
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
shape_element_relationship *shape_element_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<shape_element_relationship *>(s);
      }
   return NULL;
   }
shape_element_relationship *shape_element_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<shape_element_relationship *>(s);
      }
   return NULL;
   }
// construction factory
shape_element_relationship *shape_element_relationship::Construct() {
   shape_element_relationship *result = NULL;

   // create the shape_element_relationship.
   result = new shape_element_relationship();
   return result;
   }
bool shape_element_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: shape_element_relationship\r\n");

   // Check for the existence of all required attributes
   if (_relating_shape_element == NULL) {
      TRACE("ERROR: _relating_shape_element a required attribute is NULL!\r\n");
      result = false;
      }
   if (_related_shape_element == NULL) {
      TRACE("ERROR: _related_shape_element a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
