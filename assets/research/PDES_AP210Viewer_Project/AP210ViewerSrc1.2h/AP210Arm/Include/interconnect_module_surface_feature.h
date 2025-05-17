#ifndef INTERCONNECT_MODULE_SURFACE_FEATURE_H
#define INTERCONNECT_MODULE_SURFACE_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_feature.h>

// Unions

// Enumerations

class AP210ARM_API interconnect_module_surface_feature:
public part_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 592};

   private:
      // Required attributes

      // Optional attributes

   protected:
      interconnect_module_surface_feature();

   public:
      ~interconnect_module_surface_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interconnect_module_surface_feature *InstanceOf(ARMObject *);
      static interconnect_module_surface_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interconnect_module_surface_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
