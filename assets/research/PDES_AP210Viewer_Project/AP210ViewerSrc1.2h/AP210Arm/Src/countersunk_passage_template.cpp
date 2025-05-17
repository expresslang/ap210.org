// Source for AP210 application object
//     countersunk_passage_template

// Precompiled include files
#include <StdAfx.h>

#include "countersunk_passage_template.h"

// Classes
#include <unsupported_passage_template.h>
#include <blind_passage_template.h>

countersunk_passage_template::countersunk_passage_template() {
   initialize();
   }
countersunk_passage_template::~countersunk_passage_template() {
   // Free string attributes
   }
// intialize data members
void countersunk_passage_template::initialize() {
   // Required attributes
   _constant_diameter_passage = NULL;
   _tapered_passage = NULL;

   // Optional attributes
   }
// Runtime type identification
int countersunk_passage_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = unsupported_passage_template::DynamicType(ID);
      }
   return result;
   }
countersunk_passage_template *countersunk_passage_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<countersunk_passage_template *>(s);
      }
   return NULL;
   }
countersunk_passage_template *countersunk_passage_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<countersunk_passage_template *>(s);
      }
   return NULL;
   }
// construction factory
countersunk_passage_template *countersunk_passage_template::Construct() {
   countersunk_passage_template *result = NULL;

   // create the countersunk_passage_template.
   result = new countersunk_passage_template();
   return result;
   }
bool countersunk_passage_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: countersunk_passage_template\r\n");

   // Check for the existence of all required attributes
   if (_constant_diameter_passage == NULL) {
      TRACE("ERROR: _constant_diameter_passage a required attribute is NULL!\r\n");
      result = false;
      }
   if (_tapered_passage == NULL) {
      TRACE("ERROR: _tapered_passage a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (unsupported_passage_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
