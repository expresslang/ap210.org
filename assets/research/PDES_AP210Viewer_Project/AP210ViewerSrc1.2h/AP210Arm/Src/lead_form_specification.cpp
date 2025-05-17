// Source for AP210 application object
//     lead_form_specification

// Precompiled include files
#include <StdAfx.h>

#include "lead_form_specification.h"

// Classes

lead_form_specification::lead_form_specification() {
   initialize();
   }
lead_form_specification::~lead_form_specification() {
   // Free string attributes
   }
// intialize data members
void lead_form_specification::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int lead_form_specification::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = process_specification::DynamicType(ID);
      }
   return result;
   }
lead_form_specification *lead_form_specification::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<lead_form_specification *>(s);
      }
   return NULL;
   }
lead_form_specification *lead_form_specification::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<lead_form_specification *>(s);
      }
   return NULL;
   }
// construction factory
lead_form_specification *lead_form_specification::Construct() {
   lead_form_specification *result = NULL;

   // create the lead_form_specification.
   result = new lead_form_specification();
   return result;
   }
bool lead_form_specification::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: lead_form_specification\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (process_specification::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
