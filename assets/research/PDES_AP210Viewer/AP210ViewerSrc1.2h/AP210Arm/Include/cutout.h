#ifndef CUTOUT_H
#define CUTOUT_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <inter_stratum_feature.h>

// Unions

// Enumerations

class AP210ARM_API cutout:
public inter_stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 406};

   private:
      // Required attributes

      // Optional attributes

   protected:
      cutout();

   public:
      ~cutout();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static cutout *InstanceOf(ARMObject *);
      static cutout *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static cutout *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
