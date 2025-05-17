// Source for AP210 application object
//     terminal_pair_port_equivalence_relationship

// Precompiled include files
#include <StdAfx.h>

#include "terminal_pair_port_equivalence_relationship.h"

// Classes
#include <analytical_model_port.h>

terminal_pair_port_equivalence_relationship::terminal_pair_port_equivalence_relationship() {
   initialize();
   }
terminal_pair_port_equivalence_relationship::~terminal_pair_port_equivalence_relationship() {
   // Free string attributes
   }
// intialize data members
void terminal_pair_port_equivalence_relationship::initialize() {
   // Required attributes
   _equivalent_port = NULL;

   // Optional attributes
   }
// Runtime type identification
int terminal_pair_port_equivalence_relationship::DynamicType(int ID) {
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
terminal_pair_port_equivalence_relationship *terminal_pair_port_equivalence_relationship::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<terminal_pair_port_equivalence_relationship *>(s);
      }
   return NULL;
   }
terminal_pair_port_equivalence_relationship *terminal_pair_port_equivalence_relationship::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<terminal_pair_port_equivalence_relationship *>(s);
      }
   return NULL;
   }
// construction factory
terminal_pair_port_equivalence_relationship *terminal_pair_port_equivalence_relationship::Construct() {
   terminal_pair_port_equivalence_relationship *result = NULL;

   // create the terminal_pair_port_equivalence_relationship.
   result = new terminal_pair_port_equivalence_relationship();
   return result;
   }
bool terminal_pair_port_equivalence_relationship::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: terminal_pair_port_equivalence_relationship\r\n");

   // Check for the existence of all required attributes
   if (_equivalent_port == NULL) {
      TRACE("ERROR: _equivalent_port a required attribute is NULL!\r\n");
      result = false;
      }
   if (_scalar_ports == NULL) {
      TRACE("ERROR: _scalar_ports a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
