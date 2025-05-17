#ifndef INTERCONNECT_MODULE_PRODUCT_ASSEMBLY_VIEW_FABRICATION_JOINT_H
#define INTERCONNECT_MODULE_PRODUCT_ASSEMBLY_VIEW_FABRICATION_JOINT_H

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

class AP210ARM_API interconnect_module_product_assembly_view_fabrication_joint:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 595};

   private:
      // Required attributes
      class interconnect_module_component_stratum_based_terminal *_joined_terminal[2000];

      // Optional attributes

   protected:
      interconnect_module_product_assembly_view_fabrication_joint();

   public:
      ~interconnect_module_product_assembly_view_fabrication_joint();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interconnect_module_product_assembly_view_fabrication_joint *InstanceOf(ARMObject *);
      static interconnect_module_product_assembly_view_fabrication_joint *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interconnect_module_product_assembly_view_fabrication_joint *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
