// Source for AP210 application object
//     certification

// Precompiled include files
#include <StdAfx.h>

#include "certification.h"

// Classes
#include <ee_approval.h>
#include <ee_text.h>
#include <supplied_product_version.h>

certification::certification() {
   initialize();
   }
certification::~certification() {
   // Free string attributes
   }
// intialize data members
void certification::initialize() {
   // Required attributes
   _certification_approval = NULL;
   _certification_number = NULL;
   _certified_product_version = NULL;

   // Optional attributes
   }
// Runtime type identification
int certification::DynamicType(int ID) {
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
certification *certification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<certification *>(s);
      }
   return NULL;
   }
certification *certification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<certification *>(s);
      }
   return NULL;
   }
// construction factory
certification *certification::Construct() {
   certification *result = NULL;

   // create the certification.
   result = new certification();
   return result;
   }
bool certification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: certification\r\n");

   // Check for the existence of all required attributes
   if (_certification_approval == NULL) {
      TRACE("ERROR: _certification_approval a required attribute is NULL!\r\n");
      result = false;
      }
   if (_certification_number == NULL) {
      TRACE("ERROR: _certification_number a required attribute is NULL!\r\n");
      result = false;
      }
   if (_certified_product_version == NULL) {
      TRACE("ERROR: _certified_product_version a required attribute is NULL!\r\n");
      result = false;
      }
   if (_certification_date == NULL) {
      TRACE("ERROR: _certification_date a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
