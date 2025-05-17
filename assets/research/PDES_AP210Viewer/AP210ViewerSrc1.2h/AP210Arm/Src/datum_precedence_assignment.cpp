// Source for AP210 application object
//     datum_precedence_assignment

// Precompiled include files
#include <StdAfx.h>

#include "datum_precedence_assignment.h"

// Classes
#include <datum_usage_in_datum_system_relationship.h>

datum_precedence_assignment::datum_precedence_assignment() {
   initialize();
   }
datum_precedence_assignment::~datum_precedence_assignment() {
   // Free string attributes
   }
// intialize data members
void datum_precedence_assignment::initialize() {
   // Required attributes
   _assigned_to = NULL;

   // Optional attributes
   }
// Runtime type identification
int datum_precedence_assignment::DynamicType(int ID) {
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
datum_precedence_assignment *datum_precedence_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<datum_precedence_assignment *>(s);
      }
   return NULL;
   }
datum_precedence_assignment *datum_precedence_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<datum_precedence_assignment *>(s);
      }
   return NULL;
   }
// construction factory
datum_precedence_assignment *datum_precedence_assignment::Construct() {
   datum_precedence_assignment *result = NULL;

   // create the datum_precedence_assignment.
   result = new datum_precedence_assignment();
   return result;
   }
bool datum_precedence_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: datum_precedence_assignment\r\n");

   // Check for the existence of all required attributes
   if (_assigned_to == NULL) {
      TRACE("ERROR: _assigned_to a required attribute is NULL!\r\n");
      result = false;
      }
   if (_name == NULL) {
      TRACE("ERROR: _name a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
