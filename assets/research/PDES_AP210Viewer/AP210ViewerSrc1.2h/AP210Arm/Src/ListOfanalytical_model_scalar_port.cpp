// Source for AP210 application object
//     ListOfanalytical_model_scalar_port

// Precompiled include files
#include <StdAfx.h>

#include "ListOfanalytical_model_scalar_port.h"

// Classes
#include <analytical_model_scalar_port.h>

ListOfanalytical_model_scalar_port::ListOfanalytical_model_scalar_port() {
   initialize();
   }
ListOfanalytical_model_scalar_port::~ListOfanalytical_model_scalar_port() {
   // Free string attributes
   }
// intialize data members
void ListOfanalytical_model_scalar_port::initialize() {
   // Required attributes
   _analytical_model_scalar_port = NULL;

   // Optional attributes
   }
// Runtime type identification
int ListOfanalytical_model_scalar_port::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
ListOfanalytical_model_scalar_port *ListOfanalytical_model_scalar_port::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<ListOfanalytical_model_scalar_port *>(s);
      }
   return NULL;
   }
ListOfanalytical_model_scalar_port *ListOfanalytical_model_scalar_port::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<ListOfanalytical_model_scalar_port *>(s);
      }
   return NULL;
   }
// construction factory
ListOfanalytical_model_scalar_port *ListOfanalytical_model_scalar_port::Construct() {
   ListOfanalytical_model_scalar_port *result = NULL;

   // create the ListOfanalytical_model_scalar_port.
   result = new ListOfanalytical_model_scalar_port();
   return result;
   }
bool ListOfanalytical_model_scalar_port::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: ListOfanalytical_model_scalar_port\r\n");

   // Check for the existence of all required attributes
   if (_analytical_model_scalar_port == NULL) {
      TRACE("ERROR: _analytical_model_scalar_port a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
