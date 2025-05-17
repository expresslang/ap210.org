#ifndef ASSEMBLY_SEPARATION_REQUIREMENT_ALLOCATION_H
#define ASSEMBLY_SEPARATION_REQUIREMENT_ALLOCATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <assembly_requirement_allocation.h>

// Unions

// Enumerations

class AP210ARM_API assembly_separation_requirement_allocation:
public assembly_requirement_allocation
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 210};

   private:
      // Required attributes
      union component_or_feature *_disjoint_assignment[2000];

      // Optional attributes

   protected:
      assembly_separation_requirement_allocation();

   public:
      ~assembly_separation_requirement_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_separation_requirement_allocation *InstanceOf(ARMObject *);
      static assembly_separation_requirement_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_separation_requirement_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
