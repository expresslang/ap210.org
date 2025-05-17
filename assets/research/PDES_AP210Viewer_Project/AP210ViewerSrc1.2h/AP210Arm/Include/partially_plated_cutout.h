#ifndef PARTIALLY_PLATED_CUTOUT_H
#define PARTIALLY_PLATED_CUTOUT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <cutout.h>

// Unions

// Enumerations

class AP210ARM_API partially_plated_cutout:
public cutout
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 682};

   private:
      // Required attributes

      // Optional attributes

   protected:
      partially_plated_cutout();

   public:
      ~partially_plated_cutout();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static partially_plated_cutout *InstanceOf(ARMObject *);
      static partially_plated_cutout *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static partially_plated_cutout *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
