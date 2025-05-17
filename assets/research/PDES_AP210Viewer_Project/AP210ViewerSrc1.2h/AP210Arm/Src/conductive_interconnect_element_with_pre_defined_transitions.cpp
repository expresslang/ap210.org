// Source for AP210 application object
//     conductive_interconnect_element_with_pre_defined_transitions

// Precompiled include files
#include <StdAfx.h>

#include "conductive_interconnect_element_with_pre_defined_transitions.h"

// Classes
#include <curve.h>

conductive_interconnect_element_with_pre_defined_transitions::conductive_interconnect_element_with_pre_defined_transitions() {
   initialize();
   }
conductive_interconnect_element_with_pre_defined_transitions::~conductive_interconnect_element_with_pre_defined_transitions() {
   // Free string attributes
   }
// intialize data members
void conductive_interconnect_element_with_pre_defined_transitions::initialize() {
   // Required attributes
   _centreline_shape = NULL;

   // Optional attributes
   }
// Runtime type identification
int conductive_interconnect_element_with_pre_defined_transitions::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = conductive_interconnect_element::DynamicType(ID);
      }
   return result;
   }
conductive_interconnect_element_with_pre_defined_transitions *conductive_interconnect_element_with_pre_defined_transitions::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conductive_interconnect_element_with_pre_defined_transitions *>(s);
      }
   return NULL;
   }
conductive_interconnect_element_with_pre_defined_transitions *conductive_interconnect_element_with_pre_defined_transitions::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conductive_interconnect_element_with_pre_defined_transitions *>(s);
      }
   return NULL;
   }
// construction factory
conductive_interconnect_element_with_pre_defined_transitions *conductive_interconnect_element_with_pre_defined_transitions::Construct() {
   conductive_interconnect_element_with_pre_defined_transitions *result = NULL;

   // create the conductive_interconnect_element_with_pre_defined_transitions.
   result = new conductive_interconnect_element_with_pre_defined_transitions();
   return result;
   }
bool conductive_interconnect_element_with_pre_defined_transitions::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conductive_interconnect_element_with_pre_defined_transitions\r\n");

   // Check for the existence of all required attributes
   if (_centreline_shape == NULL) {
      TRACE("ERROR: _centreline_shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_connected_points == NULL) {
      TRACE("ERROR: _connected_points a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (conductive_interconnect_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
