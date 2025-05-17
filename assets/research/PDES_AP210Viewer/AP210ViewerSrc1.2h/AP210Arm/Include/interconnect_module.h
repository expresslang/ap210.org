#ifndef INTERCONNECT_MODULE_H
#define INTERCONNECT_MODULE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <physical_unit_design_view.h>

// Unions

// Enumerations

class AP210ARM_API interconnect_module:
public physical_unit_design_view
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 583};

   private:
      // Required attributes

      // Optional attributes
      class assembly_module *_assembly_design_requirement[2000];

   protected:
      interconnect_module();

   public:
      ~interconnect_module();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interconnect_module *InstanceOf(ARMObject *);
      static interconnect_module *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interconnect_module *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
