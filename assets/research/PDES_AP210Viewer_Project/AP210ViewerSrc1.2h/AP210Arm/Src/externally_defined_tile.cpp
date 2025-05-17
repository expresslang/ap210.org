// Source for AP210 application object
//     externally_defined_tile

// Precompiled include files
#include <StdAfx.h>

#include "externally_defined_tile.h"

// Classes

externally_defined_tile::externally_defined_tile() {
   initialize();
   }
externally_defined_tile::~externally_defined_tile() {
   // Free string attributes
   }
// intialize data members
void externally_defined_tile::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int externally_defined_tile::DynamicType(int ID) {
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
externally_defined_tile *externally_defined_tile::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<externally_defined_tile *>(s);
      }
   return NULL;
   }
externally_defined_tile *externally_defined_tile::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<externally_defined_tile *>(s);
      }
   return NULL;
   }
// construction factory
externally_defined_tile *externally_defined_tile::Construct() {
   externally_defined_tile *result = NULL;

   // create the externally_defined_tile.
   result = new externally_defined_tile();
   return result;
   }
bool externally_defined_tile::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: externally_defined_tile\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (managed_design_object::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
