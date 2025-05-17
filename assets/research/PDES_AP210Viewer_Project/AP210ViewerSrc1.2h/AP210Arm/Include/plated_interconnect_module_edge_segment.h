#ifndef PLATED_INTERCONNECT_MODULE_EDGE_SEGMENT_H
#define PLATED_INTERCONNECT_MODULE_EDGE_SEGMENT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <plated_inter_stratum_feature.h>
#include <interconnect_module_edge_segment.h>

// Unions

// Enumerations

class AP210ARM_API plated_interconnect_module_edge_segment:
public plated_inter_stratum_feature,
public interconnect_module_edge_segment
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 713};

   private:
      // Required attributes

      // Optional attributes

   protected:
      plated_interconnect_module_edge_segment();

   public:
      ~plated_interconnect_module_edge_segment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static plated_interconnect_module_edge_segment *InstanceOf(ARMObject *);
      static plated_interconnect_module_edge_segment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static plated_interconnect_module_edge_segment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
