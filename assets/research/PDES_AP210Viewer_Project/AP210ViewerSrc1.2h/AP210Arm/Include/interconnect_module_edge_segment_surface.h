#ifndef INTERCONNECT_MODULE_EDGE_SEGMENT_SURFACE_H
#define INTERCONNECT_MODULE_EDGE_SEGMENT_SURFACE_H

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

class AP210ARM_API interconnect_module_edge_segment_surface:
public interconnect_module_surface_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 591};

   private:
      // Required attributes
      class interconnect_module_edge_surface *_composed_surface;
      class edge_segment_vertex *_start_vertex;
      class edge_segment_vertex *_end_vertex;

      // Optional attributes

   protected:
      interconnect_module_edge_segment_surface();

   public:
      ~interconnect_module_edge_segment_surface();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interconnect_module_edge_segment_surface *InstanceOf(ARMObject *);
      static interconnect_module_edge_segment_surface *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interconnect_module_edge_segment_surface *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
