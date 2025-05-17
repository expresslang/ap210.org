// Source for AP210 application object
//     pca_usage_view

// Precompiled include files
#include <StdAfx.h>

#include "pca_usage_view.h"

// Classes

pca_usage_view::pca_usage_view() {
   initialize();
   }
pca_usage_view::~pca_usage_view() {
   // Free string attributes
   }
// intialize data members
void pca_usage_view::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int pca_usage_view::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_module_usage_view::DynamicType(ID);
      }
   return result;
   }
pca_usage_view *pca_usage_view::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<pca_usage_view *>(s);
      }
   return NULL;
   }
pca_usage_view *pca_usage_view::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<pca_usage_view *>(s);
      }
   return NULL;
   }
// construction factory
pca_usage_view *pca_usage_view::Construct() {
   pca_usage_view *result = NULL;

   // create the pca_usage_view.
   result = new pca_usage_view();
   return result;
   }
bool pca_usage_view::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: pca_usage_view\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_module_usage_view::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
