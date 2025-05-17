#ifndef THERMAL_REQUIREMENT_ALLOCATION_H
#define THERMAL_REQUIREMENT_ALLOCATION_H

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

class AP210ARM_API thermal_requirement_allocation:
public assembly_requirement_allocation
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 834};

   private:
      // Required attributes

      // Optional attributes

   protected:
      thermal_requirement_allocation();

   public:
      ~thermal_requirement_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static thermal_requirement_allocation *InstanceOf(ARMObject *);
      static thermal_requirement_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static thermal_requirement_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
