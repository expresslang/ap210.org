#ifndef BOND_ASSEMBLY_POSITION_H
#define BOND_ASSEMBLY_POSITION_H

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

class AP210ARM_API bond_assembly_position:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 234};

   private:
      // Required attributes
      class assembled_with_bonding *_bond;
      class physical_unit_3d_shape *_assembly_model;
      class default_assembly_bond_shape *_bond_model;
      class axis_placement_3d *_bond_definition_placement;

      // Optional attributes

   protected:
      bond_assembly_position();

   public:
      ~bond_assembly_position();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static bond_assembly_position *InstanceOf(ARMObject *);
      static bond_assembly_position *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static bond_assembly_position *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
