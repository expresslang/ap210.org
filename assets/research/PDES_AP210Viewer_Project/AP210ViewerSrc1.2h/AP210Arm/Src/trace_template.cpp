// Source for AP210 application object
//     trace_template

// Precompiled include files
#include <StdAfx.h>

#include "trace_template.h"

// Classes
#include <curve_style.h>

trace_template::trace_template() {
   initialize();
   }
trace_template::~trace_template() {
   // Free string attributes
   }
// intialize data members
void trace_template::initialize() {
   // Required attributes
   _trace_style = NULL;

   // Optional attributes
   }
// Runtime type identification
int trace_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_template::DynamicType(ID);
      }
   return result;
   }
trace_template *trace_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<trace_template *>(s);
      }
   return NULL;
   }
trace_template *trace_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<trace_template *>(s);
      }
   return NULL;
   }
// construction factory
trace_template *trace_template::Construct() {
   trace_template *result = NULL;

   // create the trace_template.
   result = new trace_template();
   return result;
   }
bool trace_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: trace_template\r\n");

   // Check for the existence of all required attributes
   if (_trace_style == NULL) {
      TRACE("ERROR: _trace_style a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
