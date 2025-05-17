// Source for AP210 application object
//     fiducial

// Precompiled include files
#include <StdAfx.h>

#include "fiducial.h"

// Classes

fiducial::fiducial() {
   initialize();
   }
fiducial::~fiducial() {
   // Free string attributes
   }
// intialize data members
void fiducial::initialize() {
   // Required attributes

   // Optional attributes
   }
// Runtime type identification
int fiducial::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   if (result == 0) {
      result = laminate_component::DynamicType(ID);
      }
   return result;
   }
fiducial *fiducial::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<fiducial *>(s);
      }
   return NULL;
   }
fiducial *fiducial::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<fiducial *>(s);
      }
   return NULL;
   }
// construction factory
fiducial *fiducial::Construct() {
   fiducial *result = NULL;

   // create the fiducial.
   result = new fiducial();
   return result;
   }
bool fiducial::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: fiducial\r\n");

   // Check for the existence of all required attributes
   // Check supertypes for the existence of all required attributes
   if (laminate_component::hasRequiredAttributes() == false) {
      result = false;
      }
   return(result);
   }
