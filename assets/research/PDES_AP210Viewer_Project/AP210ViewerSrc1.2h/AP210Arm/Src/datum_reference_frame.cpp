// Source for AP210 application object
//     datum_reference_frame

// Precompiled include files
#include <StdAfx.h>

#include "datum_reference_frame.h"

// Classes
#include <datum_point.h>

datum_reference_frame::datum_reference_frame() {
   initialize();
   }
datum_reference_frame::~datum_reference_frame() {
   // Free string attributes
   }
// intialize data members
void datum_reference_frame::initialize() {
   // Required attributes

   // Optional attributes
   _reference_origin = NULL;
   }
// Runtime type identification
int datum_reference_frame::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = non_feature_shape_element::DynamicType(ID);
      }
   return result;
   }
datum_reference_frame *datum_reference_frame::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_reference_frame *>(s);
      }
   return NULL;
   }
datum_reference_frame *datum_reference_frame::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_reference_frame *>(s);
      }
   return NULL;
   }
// construction factory
datum_reference_frame *datum_reference_frame::Construct() {
   datum_reference_frame *result = NULL;

   // create the datum_reference_frame.
   result = new datum_reference_frame();
   return result;
   }
bool datum_reference_frame::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_reference_frame\r\n");

   // Check for the existence of all required attributes
   if (_reference_planes == NULL) {
      TRACE("ERROR: _reference_planes a required attribute is NULL!\r\n");
      result = false;
      }
   if (_reference_axes == NULL) {
      TRACE("ERROR: _reference_axes a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (non_feature_shape_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
