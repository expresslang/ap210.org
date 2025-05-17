// Source for AP210 application object
//     default_trace_template

// Precompiled include files
#include <StdAfx.h>

#include "default_trace_template.h"

// Classes
#include <stratum_technology.h>

default_trace_template::default_trace_template() {
   initialize();
   }
default_trace_template::~default_trace_template() {
   // Free string attributes
   }
// intialize data members
void default_trace_template::initialize() {
   // Required attributes
   _of_stratum_technology = NULL;

   // Optional attributes
   }
// Runtime type identification
int default_trace_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = trace_template::DynamicType(ID);
      }
   return result;
   }
default_trace_template *default_trace_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<default_trace_template *>(s);
      }
   return NULL;
   }
default_trace_template *default_trace_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<default_trace_template *>(s);
      }
   return NULL;
   }
// construction factory
default_trace_template *default_trace_template::Construct() {
   default_trace_template *result = NULL;

   // create the default_trace_template.
   result = new default_trace_template();
   return result;
   }
bool default_trace_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: default_trace_template\r\n");

   // Check for the existence of all required attributes
   if (_of_stratum_technology == NULL) {
      TRACE("ERROR: _of_stratum_technology a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (trace_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
