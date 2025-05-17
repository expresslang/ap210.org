// Source for AP210 application object
//     part_template

// Precompiled include files
#include <StdAfx.h>

#include "part_template.h"

// Classes
#include <analytical_model.h>

part_template::part_template() {
   initialize();
   }
part_template::~part_template() {
   // Free string attributes
   }
// intialize data members
void part_template::initialize() {
   // Required attributes

   // Optional attributes
   _part_template_analytical_model = NULL;
   }
// Runtime type identification
int part_template::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = library_item::DynamicType(ID);
      }
   if (result == 0) {
      result = physical_feature_or_part_template::DynamicType(ID);
      }
   return result;
   }
part_template *part_template::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_template *>(s);
      }
   return NULL;
   }
part_template *part_template::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_template *>(s);
      }
   return NULL;
   }
// construction factory
part_template *part_template::Construct() {
   part_template *result = NULL;

   // create the part_template.
   result = new part_template();
   return result;
   }
bool part_template::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_template\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (library_item::hasRequiredAttributes() == false) {
      result = false;
      }
   if (physical_feature_or_part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
