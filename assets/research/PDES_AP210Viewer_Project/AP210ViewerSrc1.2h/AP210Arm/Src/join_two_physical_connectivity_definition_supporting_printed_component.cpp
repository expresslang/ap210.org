// Source for AP210 application object
//     join_two_physical_connectivity_definition_supporting_printed_component

// Precompiled include files
#include <StdAfx.h>

#include "join_two_physical_connectivity_definition_supporting_printed_component.h"

// Classes

join_two_physical_connectivity_definition_supporting_printed_component::join_two_physical_connectivity_definition_supporting_printed_component() {
   initialize();
   }
join_two_physical_connectivity_definition_supporting_printed_component::~join_two_physical_connectivity_definition_supporting_printed_component() {
   // Free string attributes
   }
// intialize data members
void join_two_physical_connectivity_definition_supporting_printed_component::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int join_two_physical_connectivity_definition_supporting_printed_component::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = printed_component::DynamicType(ID);
      }
   return result;
   }
join_two_physical_connectivity_definition_supporting_printed_component *join_two_physical_connectivity_definition_supporting_printed_component::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<join_two_physical_connectivity_definition_supporting_printed_component *>(s);
      }
   return NULL;
   }
join_two_physical_connectivity_definition_supporting_printed_component *join_two_physical_connectivity_definition_supporting_printed_component::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<join_two_physical_connectivity_definition_supporting_printed_component *>(s);
      }
   return NULL;
   }
// construction factory
join_two_physical_connectivity_definition_supporting_printed_component *join_two_physical_connectivity_definition_supporting_printed_component::Construct() {
   join_two_physical_connectivity_definition_supporting_printed_component *result = NULL;

   // create the join_two_physical_connectivity_definition_supporting_printed_component.
   result = new join_two_physical_connectivity_definition_supporting_printed_component();
   return result;
   }
bool join_two_physical_connectivity_definition_supporting_printed_component::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: join_two_physical_connectivity_definition_supporting_printed_component\r\n");

   // Check for the existence of all required attributes
   if (_joined_definitions == NULL) {
      TRACE("ERROR: _joined_definitions a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (printed_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
