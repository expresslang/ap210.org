#ifndef PLATED_INTERCONNECT_MODULE_EDGE_H
#define PLATED_INTERCONNECT_MODULE_EDGE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <interconnect_module_edge.h>
#include <plated_inter_stratum_feature.h>

// Unions

// Enumerations

class AP210ARM_API plated_interconnect_module_edge:
public interconnect_module_edge,
public plated_inter_stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 712};

   private:
      // Required attributes

      // Optional attributes

   protected:
      plated_interconnect_module_edge();

   public:
      ~plated_interconnect_module_edge();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static plated_interconnect_module_edge *InstanceOf(ARMObject *);
      static plated_interconnect_module_edge *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static plated_interconnect_module_edge *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
