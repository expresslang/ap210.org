// Source for AP210 application object
//     polarity_indication_feature

// Precompiled include files
#include <StdAfx.h>

#include "polarity_indication_feature.h"

// Classes
#include <package_terminal.h>

polarity_indication_feature::polarity_indication_feature() {
   initialize();
   }
polarity_indication_feature::~polarity_indication_feature() {
   // Free string attributes
   }
// intialize data members
void polarity_indication_feature::initialize() {
   // Required attributes
   _associated_terminal = NULL;

   // Optional attributes
   }
// Runtime type identification
int polarity_indication_feature::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = part_feature::DynamicType(ID);
      }
   return result;
   }
polarity_indication_feature *polarity_indication_feature::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<polarity_indication_feature *>(s);
      }
   return NULL;
   }
polarity_indication_feature *polarity_indication_feature::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<polarity_indication_feature *>(s);
      }
   return NULL;
   }
// construction factory
polarity_indication_feature *polarity_indication_feature::Construct() {
   polarity_indication_feature *result = NULL;

   // create the polarity_indication_feature.
   result = new polarity_indication_feature();
   return result;
   }
bool polarity_indication_feature::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: polarity_indication_feature\r\n");

   // Check for the existence of all required attributes
   if (_associated_terminal == NULL) {
      TRACE("ERROR: _associated_terminal a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   if (part_feature::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
