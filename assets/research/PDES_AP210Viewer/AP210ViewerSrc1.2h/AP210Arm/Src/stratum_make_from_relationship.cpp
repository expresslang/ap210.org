// Source for AP210 application object
//     stratum_make_from_relationship

// Precompiled include files
#include <StdAfx.h>

#include "stratum_make_from_relationship.h"

// Classes
#include <stratum.h>
#include <stratum.h>

stratum_make_from_relationship::stratum_make_from_relationship() {
   initialize();
   }
stratum_make_from_relationship::~stratum_make_from_relationship() {
   // Free string attributes
   }
// intialize data members
void stratum_make_from_relationship::initialize() {
   // Required attributes
   _reusable_stratum = NULL;
   _resultant_stratum = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_make_from_relationship::DynamicType(int ID) {
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
stratum_make_from_relationship *stratum_make_from_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_make_from_relationship *>(s);
      }
   return NULL;
   }
stratum_make_from_relationship *stratum_make_from_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_make_from_relationship *>(s);
      }
   return NULL;
   }
// construction factory
stratum_make_from_relationship *stratum_make_from_relationship::Construct() {
   stratum_make_from_relationship *result = NULL;

   // create the stratum_make_from_relationship.
   result = new stratum_make_from_relationship();
   return result;
   }
bool stratum_make_from_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_make_from_relationship\r\n");

   // Check for the existence of all required attributes
   if (_reusable_stratum == NULL) {
      TRACE("ERROR: _reusable_stratum a required attribute is NULL!\r\n");
      result = false;
      }
   if (_resultant_stratum == NULL) {
      TRACE("ERROR: _resultant_stratum a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
