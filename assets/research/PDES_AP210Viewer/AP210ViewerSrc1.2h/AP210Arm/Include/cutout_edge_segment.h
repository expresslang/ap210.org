#ifndef CUTOUT_EDGE_SEGMENT_H
#define CUTOUT_EDGE_SEGMENT_H

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

class AP210ARM_API cutout_edge_segment:
public inter_stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 407};

   private:
      // Required attributes
      class cutout *_composed_cutout;
      class edge_segment_vertex *_start_vertex;
      class edge_segment_vertex *_end_vertex;

      // Optional attributes

   protected:
      cutout_edge_segment();

   public:
      ~cutout_edge_segment();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static cutout_edge_segment *InstanceOf(ARMObject *);
      static cutout_edge_segment *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static cutout_edge_segment *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
