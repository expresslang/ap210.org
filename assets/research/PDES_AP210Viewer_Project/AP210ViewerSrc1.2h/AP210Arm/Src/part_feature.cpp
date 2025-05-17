// Source for AP210 application object
//     part_feature

// Precompiled include files
#include <StdAfx.h>

#include "part_feature.h"

// Classes
#include <physical_unit_usage_view.h>
#include <part_feature.h>

part_feature::part_feature() {
   initialize();
   }
part_feature::~part_feature() {
   // Free string attributes
   }
// intialize data members
void part_feature::initialize() {
   // Required attributes
   _associated_definition = NULL;

   // Optional attributes
   _precedent_feature = NULL;
   }
// Runtime type identification
int part_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = physical_feature_or_part_template::DynamicType(ID);
      }
   return result;
   }
part_feature *part_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<part_feature *>(s);
      }
   return NULL;
   }
part_feature *part_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<part_feature *>(s);
      }
   return NULL;
   }
// construction factory
part_feature *part_feature::Construct() {
   part_feature *result = NULL;

   // create the part_feature.
   result = new part_feature();
   return result;
   }
bool part_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: part_feature\r\n");

   // Check for the existence of all required attributes
   if (_associated_definition == NULL) {
      TRACE("ERROR: _associated_definition a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (physical_feature_or_part_template::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
