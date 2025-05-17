#ifndef DIELECTRIC_MATERIAL_PASSAGE_H
#define DIELECTRIC_MATERIAL_PASSAGE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <inter_stratum_feature.h>

// Unions
#include <material_or_specification.h>

// Enumerations

class AP210ARM_API dielectric_material_passage:
public inter_stratum_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 495};

   private:
      // Required attributes
      class cutout *_precedent_passage;

      // Optional attributes
      union material_or_specification *_feature_material;

   protected:
      dielectric_material_passage();

   public:
      ~dielectric_material_passage();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static dielectric_material_passage *InstanceOf(ARMObject *);
      static dielectric_material_passage *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static dielectric_material_passage *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
