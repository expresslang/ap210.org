#ifndef VIA_H
#define VIA_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <plated_passage.h>

// Unions

// Enumerations

class AP210ARM_API via:
public plated_passage
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 227};

   private:
      // Required attributes

      // Optional attributes

   protected:
      via();

   public:
      ~via();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static via *InstanceOf(ARMObject *);
      static via *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static via *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
