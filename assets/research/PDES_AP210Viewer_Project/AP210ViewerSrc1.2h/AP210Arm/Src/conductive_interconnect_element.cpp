// Source for AP210 application object
//     conductive_interconnect_element

// Precompiled include files
#include <StdAfx.h>

#include "conductive_interconnect_element.h"

// Classes
#include <stratum_feature.h>

conductive_interconnect_element::conductive_interconnect_element() {
   initialize();
   }
conductive_interconnect_element::~conductive_interconnect_element() {
   // Free string attributes
   }
// intialize data members
void conductive_interconnect_element::initialize() {
   // Required attributes
   _composed_conductor = NULL;

   // Optional attributes
   }
// Runtime type identification
int conductive_interconnect_element::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = laminate_component::DynamicType(ID);
      }
   return result;
   }
conductive_interconnect_element *conductive_interconnect_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conductive_interconnect_element *>(s);
      }
   return NULL;
   }
conductive_interconnect_element *conductive_interconnect_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conductive_interconnect_element *>(s);
      }
   return NULL;
   }
// construction factory
conductive_interconnect_element *conductive_interconnect_element::Construct() {
   conductive_interconnect_element *result = NULL;

   // create the conductive_interconnect_element.
   result = new conductive_interconnect_element();
   return result;
   }
bool conductive_interconnect_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conductive_interconnect_element\r\n");

   // Check for the existence of all required attributes
   if (_composed_conductor == NULL) {
      TRACE("ERROR: _composed_conductor a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
