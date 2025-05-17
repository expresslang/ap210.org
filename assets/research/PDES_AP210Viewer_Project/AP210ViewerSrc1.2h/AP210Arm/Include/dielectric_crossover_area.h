#ifndef DIELECTRIC_CROSSOVER_AREA_H
#define DIELECTRIC_CROSSOVER_AREA_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <stratum_concept_relationship.h>

// Unions

// Enumerations

class AP210ARM_API dielectric_crossover_area:
public stratum_concept_relationship
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 494};

   private:
      // Required attributes
      class stratum_feature *_related_concept;
      class stratum_feature *_relating_concept;
      class stratum_feature *_resulting_dielectric_crossover;

      // Optional attributes

   protected:
      dielectric_crossover_area();

   public:
      ~dielectric_crossover_area();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dielectric_crossover_area *InstanceOf(ARMObject *);
      static dielectric_crossover_area *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dielectric_crossover_area *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
