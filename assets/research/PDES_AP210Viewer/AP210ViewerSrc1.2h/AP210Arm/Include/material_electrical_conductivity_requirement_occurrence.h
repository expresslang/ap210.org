#ifndef MATERIAL_ELECTRICAL_CONDUCTIVITY_REQUIREMENT_OCCURRENCE_H
#define MATERIAL_ELECTRICAL_CONDUCTIVITY_REQUIREMENT_OCCURRENCE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <electrical_requirement_occurrence.h>

// Unions

// Enumerations
#include <material_conductivity_classification.h>

class AP210ARM_API material_electrical_conductivity_requirement_occurrence:
public electrical_requirement_occurrence
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 648};

   private:
      // Required attributes
      material_conductivity_classification::material_conductivity_classification _electrical_conductivity_characteristic;

      // Optional attributes

   protected:
      material_electrical_conductivity_requirement_occurrence();

   public:
      ~material_electrical_conductivity_requirement_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static material_electrical_conductivity_requirement_occurrence *InstanceOf(ARMObject *);
      static material_electrical_conductivity_requirement_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static material_electrical_conductivity_requirement_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
