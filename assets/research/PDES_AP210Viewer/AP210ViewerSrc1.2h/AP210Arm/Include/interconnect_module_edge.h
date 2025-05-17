#ifndef INTERCONNECT_MODULE_EDGE_H
#define INTERCONNECT_MODULE_EDGE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <inter_stratum_feature.h>

// Unions

// Enumerations

class AP210ARM_API interconnect_module_edge:
public inter_stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 589};

   private:
      // Required attributes

      // Optional attributes

   protected:
      interconnect_module_edge();

   public:
      ~interconnect_module_edge();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interconnect_module_edge *InstanceOf(ARMObject *);
      static interconnect_module_edge *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interconnect_module_edge *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
