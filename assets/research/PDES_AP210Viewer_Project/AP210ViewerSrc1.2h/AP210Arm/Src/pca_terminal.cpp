// Source for AP210 application object
//     pca_terminal

// Precompiled include files
#include <StdAfx.h>

#include "pca_terminal.h"

// Classes

pca_terminal::pca_terminal() {
   initialize();
   }
pca_terminal::~pca_terminal() {
   // Free string attributes
   }
// intialize data members
void pca_terminal::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int pca_terminal::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = assembly_module_terminal::DynamicType(ID);
      }
   return result;
   }
pca_terminal *pca_terminal::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<pca_terminal *>(s);
      }
   return NULL;
   }
pca_terminal *pca_terminal::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<pca_terminal *>(s);
      }
   return NULL;
   }
// construction factory
pca_terminal *pca_terminal::Construct() {
   pca_terminal *result = NULL;

   // create the pca_terminal.
   result = new pca_terminal();
   return result;
   }
bool pca_terminal::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: pca_terminal\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (assembly_module_terminal::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
