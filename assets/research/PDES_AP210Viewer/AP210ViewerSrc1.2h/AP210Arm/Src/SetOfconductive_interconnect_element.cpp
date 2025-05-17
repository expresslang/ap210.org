// Source for AP210 application object
//     SetOfconductive_interconnect_element

// Precompiled include files
#include <StdAfx.h>

#include "SetOfconductive_interconnect_element.h"

// Classes
#include <conductive_interconnect_element.h>

SetOfconductive_interconnect_element::SetOfconductive_interconnect_element() {
   initialize();
   }
SetOfconductive_interconnect_element::~SetOfconductive_interconnect_element() {
   // Free string attributes
   }
// intialize data members
void SetOfconductive_interconnect_element::initialize() {
   // Required attributes
   _conductive_interconnect_element = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfconductive_interconnect_element::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfconductive_interconnect_element *SetOfconductive_interconnect_element::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfconductive_interconnect_element *>(s);
      }
   return NULL;
   }
SetOfconductive_interconnect_element *SetOfconductive_interconnect_element::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfconductive_interconnect_element *>(s);
      }
   return NULL;
   }
// construction factory
SetOfconductive_interconnect_element *SetOfconductive_interconnect_element::Construct() {
   SetOfconductive_interconnect_element *result = NULL;

   // create the SetOfconductive_interconnect_element.
   result = new SetOfconductive_interconnect_element();
   return result;
   }
bool SetOfconductive_interconnect_element::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfconductive_interconnect_element\r\n");

   // Check for the existence of all required attributes
   if (_conductive_interconnect_element == NULL) {
      TRACE("ERROR: _conductive_interconnect_element a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
