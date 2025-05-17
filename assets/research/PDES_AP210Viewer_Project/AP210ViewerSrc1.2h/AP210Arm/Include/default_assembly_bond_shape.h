#ifndef DEFAULT_ASSEMBLY_BOND_SHAPE_H
#define DEFAULT_ASSEMBLY_BOND_SHAPE_H

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

class AP210ARM_API default_assembly_bond_shape:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 236};

   private:
      // Required attributes
      class assembly_bond_definition *_characterized_bond_definition;

      // Optional attributes

   protected:
      default_assembly_bond_shape();

   public:
      ~default_assembly_bond_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static default_assembly_bond_shape *InstanceOf(ARMObject *);
      static default_assembly_bond_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static default_assembly_bond_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
