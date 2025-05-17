#ifndef SHIELD_ALLOCATION_H
#define SHIELD_ALLOCATION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <electromagnetic_compatibility_requirement_allocation.h>

// Unions

// Enumerations

class AP210ARM_API shield_allocation:
public electromagnetic_compatibility_requirement_allocation
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 787};

   private:
      // Required attributes

      // Optional attributes

   protected:
      shield_allocation();

   public:
      ~shield_allocation();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static shield_allocation *InstanceOf(ARMObject *);
      static shield_allocation *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static shield_allocation *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
