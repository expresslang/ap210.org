// Source for AP210 application object
//     curve_style

// Precompiled include files
#include <StdAfx.h>

#include "curve_style.h"

// Classes
#include <length_data_element.h>

curve_style::curve_style() {
   initialize();
   }
curve_style::~curve_style() {
   // Free string attributes
   if (_name != NULL) {
      free(_name);
     }
   }
// intialize data members
void curve_style::initialize() {
   // Required attributes
   _name = NULL;
   _curve_width = NULL;

   // Optional attributes
   }
// Runtime type identification
int curve_style::DynamicType(int ID) {
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
curve_style *curve_style::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<curve_style *>(s);
      }
   return NULL;
   }
curve_style *curve_style::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<curve_style *>(s);
      }
   return NULL;
   }
// construction factory
curve_style *curve_style::Construct() {
   curve_style *result = NULL;

   // create the curve_style.
   result = new curve_style();
   return result;
   }
bool curve_style::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: curve_style\r\n");

   // Check for the existence of all required attributes
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   if (_corner_style == NULL) {
      TRACE("ERROR: _corner_style a required attribute is NULL!\r\n");
      result = false;
      }
   if (_curve_width == NULL) {
      TRACE("ERROR: _curve_width a required attribute is NULL!\r\n");
      result = false;
      }
   if (_end_extension == NULL) {
      TRACE("ERROR: _end_extension a required attribute is NULL!\r\n");
      result = false;
      }
   if (_end_style == NULL) {
      TRACE("ERROR: _end_style a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
