// Source for AP210 application object
//     conductive_interconnect_element_with_user_defined_single_transition

// Precompiled include files
#include <StdAfx.h>

#include "conductive_interconnect_element_with_user_defined_single_transition.h"

// Classes
#include <trace_template.h>
#include <trace_template.h>
#include <layer_connection_point.h>
#include <layer_connection_point.h>

conductive_interconnect_element_with_user_defined_single_transition::conductive_interconnect_element_with_user_defined_single_transition() {
   initialize();
   }
conductive_interconnect_element_with_user_defined_single_transition::~conductive_interconnect_element_with_user_defined_single_transition() {
   // Free string attributes
   }
// intialize data members
void conductive_interconnect_element_with_user_defined_single_transition::initialize() {
   // Required attributes
   _start_definition = NULL;
   _end_definition = NULL;
   _start_terminus = NULL;
   _end_terminus = NULL;

   // Optional attributes
   }
// Runtime type identification
int conductive_interconnect_element_with_user_defined_single_transition::DynamicType(int ID) {
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
conductive_interconnect_element_with_user_defined_single_transition *conductive_interconnect_element_with_user_defined_single_transition::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conductive_interconnect_element_with_user_defined_single_transition *>(s);
      }
   return NULL;
   }
conductive_interconnect_element_with_user_defined_single_transition *conductive_interconnect_element_with_user_defined_single_transition::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conductive_interconnect_element_with_user_defined_single_transition *>(s);
      }
   return NULL;
   }
// construction factory
conductive_interconnect_element_with_user_defined_single_transition *conductive_interconnect_element_with_user_defined_single_transition::Construct() {
   conductive_interconnect_element_with_user_defined_single_transition *result = NULL;

   // create the conductive_interconnect_element_with_user_defined_single_transition.
   result = new conductive_interconnect_element_with_user_defined_single_transition();
   return result;
   }
bool conductive_interconnect_element_with_user_defined_single_transition::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conductive_interconnect_element_with_user_defined_single_transition\r\n");

   // Check for the existence of all required attributes
   if (_start_definition == NULL) {
      TRACE("ERROR: _start_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_end_definition == NULL) {
      TRACE("ERROR: _end_definition a required attribute is NULL!\r\n");
      result = false;
      }
   if (_left_curve_shape_representation == NULL) {
      TRACE("ERROR: _left_curve_shape_representation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_right_curve_shape_representation == NULL) {
      TRACE("ERROR: _right_curve_shape_representation a required attribute is NULL!\r\n");
      result = false;
      }
   if (_start_terminus == NULL) {
      TRACE("ERROR: _start_terminus a required attribute is NULL!\r\n");
      result = false;
      }
   if (_end_terminus == NULL) {
      TRACE("ERROR: _end_terminus a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (conductive_interconnect_element::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
