// Source for AP210 application object
//     counterbore_passage_template

// Precompiled include files
#include <StdAfx.h>

#include "counterbore_passage_template.h"

// Classes
#include <unsupported_passage_template.h>
#include <blind_passage_template.h>

counterbore_passage_template::counterbore_passage_template() {
   initialize();
   }
counterbore_passage_template::~counterbore_passage_template() {
   // Free string attributes
   }
// intialize data members
void counterbore_passage_template::initialize() {
   // Required attributes
   _smaller_passage = NULL;
   _larger_passage = NULL;

   // Optional attributes
   }
// Runtime type identification
int counterbore_passage_template::DynamicType(int ID) {
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
counterbore_passage_template *counterbore_passage_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<counterbore_passage_template *>(s);
      }
   return NULL;
   }
counterbore_passage_template *counterbore_passage_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<counterbore_passage_template *>(s);
      }
   return NULL;
   }
// construction factory
counterbore_passage_template *counterbore_passage_template::Construct() {
   counterbore_passage_template *result = NULL;

   // create the counterbore_passage_template.
   result = new counterbore_passage_template();
   return result;
   }
bool counterbore_passage_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: counterbore_passage_template\r\n");

   // Check for the existence of all required attributes
   if (_smaller_passage == NULL) {
      TRACE("ERROR: _smaller_passage a required attribute is NULL!\r\n");
      result = false;
      }
   if (_larger_passage == NULL) {
      TRACE("ERROR: _larger_passage a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (unsupported_passage_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
