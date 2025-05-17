#ifndef EDGE_SEGMENT_VERTEX_H
#define EDGE_SEGMENT_VERTEX_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <single_datum.h>

// Unions

// Enumerations

class AP210ARM_API edge_segment_vertex:
public single_datum
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 408};

   private:
      // Required attributes

      // Optional attributes

   protected:
      edge_segment_vertex();

   public:
      ~edge_segment_vertex();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static edge_segment_vertex *InstanceOf(ARMObject *);
      static edge_segment_vertex *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static edge_segment_vertex *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
