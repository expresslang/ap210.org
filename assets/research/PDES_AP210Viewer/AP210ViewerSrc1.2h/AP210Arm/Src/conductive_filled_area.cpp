// Source for AP210 application object
//     conductive_filled_area

// Precompiled include files
#include <StdAfx.h>

#include "conductive_filled_area.h"

// Classes

conductive_filled_area::conductive_filled_area() {
   initialize();
   }
conductive_filled_area::~conductive_filled_area() {
   // Free string attributes
   }
// intialize data members
void conductive_filled_area::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int conductive_filled_area::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = stratum_feature::DynamicType(ID);
      }
   return result;
   }
conductive_filled_area *conductive_filled_area::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<conductive_filled_area *>(s);
      }
   return NULL;
   }
conductive_filled_area *conductive_filled_area::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<conductive_filled_area *>(s);
      }
   return NULL;
   }
// construction factory
conductive_filled_area *conductive_filled_area::Construct() {
   conductive_filled_area *result = NULL;

   // create the conductive_filled_area.
   result = new conductive_filled_area();
   return result;
   }
bool conductive_filled_area::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: conductive_filled_area\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (stratum_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
