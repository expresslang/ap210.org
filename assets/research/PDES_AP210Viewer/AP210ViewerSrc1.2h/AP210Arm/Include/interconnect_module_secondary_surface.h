#ifndef INTERCONNECT_MODULE_SECONDARY_SURFACE_H
#define INTERCONNECT_MODULE_SECONDARY_SURFACE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <interconnect_module_surface_feature.h>

// Unions

// Enumerations

class AP210ARM_API interconnect_module_secondary_surface:
public interconnect_module_surface_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 597};

   private:
      // Required attributes

      // Optional attributes

   protected:
      interconnect_module_secondary_surface();

   public:
      ~interconnect_module_secondary_surface();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interconnect_module_secondary_surface *InstanceOf(ARMObject *);
      static interconnect_module_secondary_surface *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interconnect_module_secondary_surface *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
