#ifndef THERMAL_FEATURE_H
#define THERMAL_FEATURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_feature.h>

// Unions

// Enumerations

class AP210ARM_API thermal_feature:
public part_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 830};

   private:
      // Required attributes

      // Optional attributes

   protected:
      thermal_feature();

   public:
      ~thermal_feature();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static thermal_feature *InstanceOf(ARMObject *);
      static thermal_feature *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static thermal_feature *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
