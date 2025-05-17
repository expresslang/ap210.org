// Source for AP210 application object
//     stratum_interconnect_module_3d_position

// Precompiled include files
#include <StdAfx.h>

#include "stratum_interconnect_module_3d_position.h"

// Classes
#include <interconnect_module_stratum_assembly_relationship.h>
#include <stratum_3d_shape.h>
#include <physical_unit_3d_shape.h>
#include <axis_placement_3d.h>

stratum_interconnect_module_3d_position::stratum_interconnect_module_3d_position() {
   initialize();
   }
stratum_interconnect_module_3d_position::~stratum_interconnect_module_3d_position() {
   // Free string attributes
   }
// intialize data members
void stratum_interconnect_module_3d_position::initialize() {
   // Required attributes
   _stratum_component = NULL;
   _stratum_shape = NULL;
   _interconnect_module_shape = NULL;
   _transformation = NULL;

   // Optional attributes
   }
// Runtime type identification
int stratum_interconnect_module_3d_position::DynamicType(int ID) {
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
stratum_interconnect_module_3d_position *stratum_interconnect_module_3d_position::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<stratum_interconnect_module_3d_position *>(s);
      }
   return NULL;
   }
stratum_interconnect_module_3d_position *stratum_interconnect_module_3d_position::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<stratum_interconnect_module_3d_position *>(s);
      }
   return NULL;
   }
// construction factory
stratum_interconnect_module_3d_position *stratum_interconnect_module_3d_position::Construct() {
   stratum_interconnect_module_3d_position *result = NULL;

   // create the stratum_interconnect_module_3d_position.
   result = new stratum_interconnect_module_3d_position();
   return result;
   }
bool stratum_interconnect_module_3d_position::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: stratum_interconnect_module_3d_position\r\n");

   // Check for the existence of all required attributes
   if (_stratum_component == NULL) {
      TRACE("ERROR: _stratum_component a required attribute is NULL!\r\n");
      result = false;
      }
   if (_stratum_shape == NULL) {
      TRACE("ERROR: _stratum_shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_interconnect_module_shape == NULL) {
      TRACE("ERROR: _interconnect_module_shape a required attribute is NULL!\r\n");
      result = false;
      }
   if (_transformation == NULL) {
      TRACE("ERROR: _transformation a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
