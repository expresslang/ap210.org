#ifndef DESIGN_FUNCTIONAL_UNIT_ALLOCATION_TO_ASSEMBLY_JOINT_H
#define DESIGN_FUNCTIONAL_UNIT_ALLOCATION_TO_ASSEMBLY_JOINT_H

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

class AP210ARM_API design_functional_unit_allocation_to_assembly_joint:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 447};

   private:
      // Required attributes
      class design_composition_path *_functional_design_definition_path;
      class assembly_joint *_implementation;

      // Optional attributes

   protected:
      design_functional_unit_allocation_to_assembly_joint();

   public:
      ~design_functional_unit_allocation_to_assembly_joint();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static design_functional_unit_allocation_to_assembly_joint *InstanceOf(ARMObject *);
      static design_functional_unit_allocation_to_assembly_joint *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static design_functional_unit_allocation_to_assembly_joint *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
