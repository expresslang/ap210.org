#ifndef PCB_H
#define PCB_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <interconnect_module.h>

// Unions

// Enumerations

class AP210ARM_API pcb:
public interconnect_module
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 642};

   private:
      // Required attributes

      // Optional attributes

   protected:
      pcb();

   public:
      ~pcb();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static pcb *InstanceOf(ARMObject *);
      static pcb *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static pcb *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
