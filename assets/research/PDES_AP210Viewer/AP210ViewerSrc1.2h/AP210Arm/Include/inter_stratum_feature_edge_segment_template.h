#ifndef INTER_STRATUM_FEATURE_EDGE_SEGMENT_TEMPLATE_H
#define INTER_STRATUM_FEATURE_EDGE_SEGMENT_TEMPLATE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <inter_stratum_feature_template.h>

// Unions

// Enumerations

class AP210ARM_API inter_stratum_feature_edge_segment_template:
public inter_stratum_feature_template
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 579};

   private:
      // Required attributes
      class inter_stratum_feature_edge_template *_composed_edge;
      class edge_segment_vertex *_start_vertex;
      class edge_segment_vertex *_end_vertex;

      // Optional attributes

   protected:
      inter_stratum_feature_edge_segment_template();

   public:
      ~inter_stratum_feature_edge_segment_template();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static inter_stratum_feature_edge_segment_template *InstanceOf(ARMObject *);
      static inter_stratum_feature_edge_segment_template *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static inter_stratum_feature_edge_segment_template *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
