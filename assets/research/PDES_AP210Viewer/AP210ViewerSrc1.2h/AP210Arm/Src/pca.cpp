// Source for AP210 application object
//     pca

// Precompiled include files
#include <StdAfx.h>

#include "pca.h"

// Classes

pca::pca() {
   initialize();
   }
pca::~pca() {
   // Free string attributes
   }
// intialize data members
void pca::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int pca::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_module::DynamicType(ID);
      }
   return result;
   }
pca *pca::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<pca *>(s);
      }
   return NULL;
   }
pca *pca::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<pca *>(s);
      }
   return NULL;
   }
// construction factory
pca *pca::Construct() {
   pca *result = NULL;

   // create the pca.
   result = new pca();
   return result;
   }
bool pca::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: pca\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_module::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
