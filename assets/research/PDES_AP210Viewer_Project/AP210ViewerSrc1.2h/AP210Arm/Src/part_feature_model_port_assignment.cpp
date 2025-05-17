// Source for AP210 application object
//     part_feature_model_port_assignment

// Precompiled include files
#include <StdAfx.h>

#include "part_feature_model_port_assignment.h"

// Classes
#include <part_feature.h>
#include <analytical_model_port.h>

part_feature_model_port_assignment::part_feature_model_port_assignment() {
   initialize();
   }
part_feature_model_port_assignment::~part_feature_model_port_assignment() {
   // Free string attributes
   }
// intialize data members
void part_feature_model_port_assignment::initialize() {
   // Required attributes
   _source = NULL;
   _target = NULL;

   // Optional attributes
   }
// Runtime type identification
int part_feature_model_port_assignment::DynamicType(int ID) {
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
part_feature_model_port_assignment *part_feature_model_port_assignment::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_feature_model_port_assignment *>(s);
      }
   return NULL;
   }
part_feature_model_port_assignment *part_feature_model_port_assignment::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_feature_model_port_assignment *>(s);
      }
   return NULL;
   }
// construction factory
part_feature_model_port_assignment *part_feature_model_port_assignment::Construct() {
   part_feature_model_port_assignment *result = NULL;

   // create the part_feature_model_port_assignment.
   result = new part_feature_model_port_assignment();
   return result;
   }
bool part_feature_model_port_assignment::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_feature_model_port_assignment\r\n");

   // Check for the existence of all required attributes
   if (_source == NULL) {
      TRACE("ERROR: _source a required attribute is NULL!\r\n");
      result = false;
      }
   if (_target == NULL) {
      TRACE("ERROR: _target a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
