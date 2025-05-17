// Source for AP210 application object
//     SetOfmodel_parameter

// Precompiled include files
#include <StdAfx.h>

#include "SetOfmodel_parameter.h"

// Classes
#include <model_parameter.h>

SetOfmodel_parameter::SetOfmodel_parameter() {
   initialize();
   }
SetOfmodel_parameter::~SetOfmodel_parameter() {
   // Free string attributes
   }
// intialize data members
void SetOfmodel_parameter::initialize() {
   // Required attributes
   _model_parameter = NULL;

   // Optional attributes
   }
// Runtime type identification
int SetOfmodel_parameter::DynamicType(int ID) {
   int result = 0;

   if (ID == typeID) {;
      result = 1;
      }
   // Check supertypes for dynamic type
   return result;
   }
SetOfmodel_parameter *SetOfmodel_parameter::InstanceOf(ARMObject *s) {
   if (s->getTypeID() == typeID) {
      return dynamic_cast<SetOfmodel_parameter *>(s);
      }
   return NULL;
   }
SetOfmodel_parameter *SetOfmodel_parameter::KindOf(ARMObject * s) {
   if (s->DynamicType(typeID)) {
      return dynamic_cast<SetOfmodel_parameter *>(s);
      }
   return NULL;
   }
// construction factory
SetOfmodel_parameter *SetOfmodel_parameter::Construct() {
   SetOfmodel_parameter *result = NULL;

   // create the SetOfmodel_parameter.
   result = new SetOfmodel_parameter();
   return result;
   }
bool SetOfmodel_parameter::hasRequiredAttributes() {
   bool result = true;

   TRACE("Checking for required attributes for: SetOfmodel_parameter\r\n");

   // Check for the existence of all required attributes
   if (_model_parameter == NULL) {
      TRACE("ERROR: _model_parameter a required attribute is NULL!\r\n");
      result = false;
      }
   // Check supertypes for the existence of all required attributes
   return(result);
   }
