#ifndef JUNCTION_VERTEX_ALLOCATION_H
#define JUNCTION_VERTEX_ALLOCATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <trace_junction_or_via.h>

// Enumerations

class AP210ARM_API junction_vertex_allocation:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 622};

   private:
      // Required attributes
      union trace_junction_or_via *_implementation_point;
      class topological_junction *_required_vertex;

      // Optional attributes

   protected:
      junction_vertex_allocation();

   public:
      ~junction_vertex_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static junction_vertex_allocation *InstanceOf(ARMObject *);
      static junction_vertex_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static junction_vertex_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
