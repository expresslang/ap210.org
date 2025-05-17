#ifndef ASSEMBLY_BOND_DEFINITION_H
#define ASSEMBLY_BOND_DEFINITION_H

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

class AP210ARM_API assembly_bond_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 188};

   private:
      // Required attributes
      class external_definition *_bond_category;
      class ee_material *_bond_material;
      class part_feature *_bonded_feature_1;
      class part_feature *_bonded_feature_2;
      STR _name;

      // Optional attributes
      class analytical_representation *_analytical_assembly_bond_representation[2000];

   protected:
      assembly_bond_definition();

   public:
      ~assembly_bond_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_bond_definition *InstanceOf(ARMObject *);
      static assembly_bond_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_bond_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
