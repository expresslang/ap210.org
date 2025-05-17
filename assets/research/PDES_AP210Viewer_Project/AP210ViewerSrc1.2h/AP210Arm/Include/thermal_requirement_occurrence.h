#ifndef THERMAL_REQUIREMENT_OCCURRENCE_H
#define THERMAL_REQUIREMENT_OCCURRENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ee_requirement_occurrence.h>

// Unions

// Enumerations

class AP210ARM_API thermal_requirement_occurrence:
public ee_requirement_occurrence
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 835};

   private:
      // Required attributes

      // Optional attributes

   protected:
      thermal_requirement_occurrence();

   public:
      ~thermal_requirement_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static thermal_requirement_occurrence *InstanceOf(ARMObject *);
      static thermal_requirement_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static thermal_requirement_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
