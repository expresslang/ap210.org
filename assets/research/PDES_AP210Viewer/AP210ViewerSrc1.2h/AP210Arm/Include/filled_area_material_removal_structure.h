#ifndef FILLED_AREA_MATERIAL_REMOVAL_STRUCTURE_H
#define FILLED_AREA_MATERIAL_REMOVAL_STRUCTURE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <material_removal_feature.h>

// Unions

// Enumerations

class AP210ARM_API filled_area_material_removal_structure:
public material_removal_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 527};

   private:
      // Required attributes

      // Optional attributes

   protected:
      filled_area_material_removal_structure();

   public:
      ~filled_area_material_removal_structure();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static filled_area_material_removal_structure *InstanceOf(ARMObject *);
      static filled_area_material_removal_structure *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static filled_area_material_removal_structure *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
