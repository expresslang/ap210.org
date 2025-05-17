#ifndef POSITIVE_RATIO_MEASURE_H
#define POSITIVE_RATIO_MEASURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions

// Enumerations

class AP210ARM_API positive_ratio_measure:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 259};

   private:
      // Required attributes

      // Optional attributes

   protected:
      positive_ratio_measure();

   public:
      ~positive_ratio_measure();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static positive_ratio_measure *InstanceOf(ARMObject *);
      static positive_ratio_measure *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static positive_ratio_measure *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
