#ifndef PLATED_CUTOUT_H
#define PLATED_CUTOUT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <cutout.h>
#include <plated_inter_stratum_feature.h>

// Unions

// Enumerations

class AP210ARM_API plated_cutout:
public cutout,
public plated_inter_stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 710};

   private:
      // Required attributes

      // Optional attributes

   protected:
      plated_cutout();

   public:
      ~plated_cutout();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static plated_cutout *InstanceOf(ARMObject *);
      static plated_cutout *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static plated_cutout *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
