#ifndef BLOCK_H
#define BLOCK_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <csg_primitive.h>

// Unions

// Enumerations

class AP210ARM_API block:
public csg_primitive
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 232};

   private:
      // Required attributes

      // Optional attributes

   protected:
      block();

   public:
      ~block();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static block *InstanceOf(ARMObject *);
      static block *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static block *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
