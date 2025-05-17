// Source for AP210 application object
//     marking

// Precompiled include files
#include <StdAfx.h>

#include "marking.h"

// Classes
#include <ee_material.h>
#include <axis_placement.h>
#include <styled_text.h>
#include <ee_specification.h>

marking::marking() {
   initialize();
   }
marking::~marking() {
   // Free string attributes
   }
// intialize data members
void marking::initialize() {
   // Required attributes
   _marking_material = NULL;
   _placement = NULL;
   _message_representation = NULL;
   _marking_specification = NULL;

   // Optional attributes
   }
// Runtime type identification
int marking::DynamicType(int ID) {
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
marking *marking::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<marking *>(s);
      }
   return NULL;
   }
marking *marking::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<marking *>(s);
      }
   return NULL;
   }
// construction factory
marking *marking::Construct() {
   marking *result = NULL;

   // create the marking.
   result = new marking();
   return result;
   }
bool marking::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: marking\r\n");

   // Check for the existence of all required attributes
   if (_marked_message == NULL) {
      TRACE("ERROR: _marked_message a required attribute is NULL!\r\n");
      result = false;
      }
   if (_marked_device == NULL) {
      TRACE("ERROR: _marked_device a required attribute is NULL!\r\n");
      result = false;
      }
   if (_marking_material == NULL) {
      TRACE("ERROR: _marking_material a required attribute is NULL!\r\n");
      result = false;
      }
   if (_placement == NULL) {
      TRACE("ERROR: _placement a required attribute is NULL!\r\n");
      result = false;
      }
   if (_message_representation == NULL) {
      TRACE("ERROR: _message_representation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_marking_specification == NULL) {
      TRACE("ERROR: _marking_specification a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
