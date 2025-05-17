#ifndef STATISTICAL_DIMENSIONAL_TOLERANCE_H
#define STATISTICAL_DIMENSIONAL_TOLERANCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <dimensional_characteristic.h>

// Unions

// Enumerations

class AP210ARM_API statistical_dimensional_tolerance:
public dimensional_characteristic
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 794};

   private:
      // Required attributes
      class ee_requirement_occurrence *_statistical_control_requirement;

      // Optional attributes
      class dimensional_characteristic *_alternate_dimension;

   protected:
      statistical_dimensional_tolerance();

   public:
      ~statistical_dimensional_tolerance();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static statistical_dimensional_tolerance *InstanceOf(ARMObject *);
      static statistical_dimensional_tolerance *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static statistical_dimensional_tolerance *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
