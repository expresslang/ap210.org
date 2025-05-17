#ifndef NEXT_HIGHER_ASSEMBLY_INTERFACE_REQUIREMENT_H
#define NEXT_HIGHER_ASSEMBLY_INTERFACE_REQUIREMENT_H

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

class AP210ARM_API next_higher_assembly_interface_requirement:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 610};

   private:
      // Required attributes
      class bound_volume_shape *_shape;
      class ee_product_version *_version_of_next_higher_assembly;

      // Optional attributes

   protected:
      next_higher_assembly_interface_requirement();

   public:
      ~next_higher_assembly_interface_requirement();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static next_higher_assembly_interface_requirement *InstanceOf(ARMObject *);
      static next_higher_assembly_interface_requirement *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static next_higher_assembly_interface_requirement *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
