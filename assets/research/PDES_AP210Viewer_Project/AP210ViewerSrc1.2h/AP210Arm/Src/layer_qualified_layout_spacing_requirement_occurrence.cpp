// Source for AP210 application object
//     layer_qualified_layout_spacing_requirement_occurrence

// Precompiled include files
#include <StdAfx.h>

#include "layer_qualified_layout_spacing_requirement_occurrence.h"

// Classes

layer_qualified_layout_spacing_requirement_occurrence::layer_qualified_layout_spacing_requirement_occurrence() {
   initialize();
   }
layer_qualified_layout_spacing_requirement_occurrence::~layer_qualified_layout_spacing_requirement_occurrence() {
   // Free string attributes
   }
// intialize data members
void layer_qualified_layout_spacing_requirement_occurrence::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int layer_qualified_layout_spacing_requirement_occurrence::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = layout_spacing_requirement_occurrence::DynamicType(ID);
      }
   return result;
   }
layer_qualified_layout_spacing_requirement_occurrence *layer_qualified_layout_spacing_requirement_occurrence::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<layer_qualified_layout_spacing_requirement_occurrence *>(s);
      }
   return NULL;
   }
layer_qualified_layout_spacing_requirement_occurrence *layer_qualified_layout_spacing_requirement_occurrence::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<layer_qualified_layout_spacing_requirement_occurrence *>(s);
      }
   return NULL;
   }
// construction factory
layer_qualified_layout_spacing_requirement_occurrence *layer_qualified_layout_spacing_requirement_occurrence::Construct() {
   layer_qualified_layout_spacing_requirement_occurrence *result = NULL;

   // create the layer_qualified_layout_spacing_requirement_occurrence.
   result = new layer_qualified_layout_spacing_requirement_occurrence();
   return result;
   }
bool layer_qualified_layout_spacing_requirement_occurrence::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: layer_qualified_layout_spacing_requirement_occurrence\r\n");

   // Check for the existence of all required attributes
   if (_layer_context == NULL) {
      TRACE("ERROR: _layer_context a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (layout_spacing_requirement_occurrence::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
