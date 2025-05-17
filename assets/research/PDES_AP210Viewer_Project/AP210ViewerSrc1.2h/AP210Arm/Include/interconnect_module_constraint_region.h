#ifndef INTERCONNECT_MODULE_CONSTRAINT_REGION_H
#define INTERCONNECT_MODULE_CONSTRAINT_REGION_H

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
#include <interconnect_module_design_object_category.h>

class AP210ARM_API interconnect_module_constraint_region:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 586};

   private:
      // Required attributes
      RoseBoolean _keepout;
      class feature_shape_occurrence *_area;
      class interconnect_module *_scope[2000];
      STR _design_specific_purpose;
      class ee_requirement_occurrence *_requirement;
      class inter_stratum_extent *_associated_stratum_extent[2000];
      interconnect_module_design_object_category::interconnect_module_design_object_category _constrained_design_object_category;

      // Optional attributes
      union interconnect_module_design_object_select *_non_conformant_interconnect_module_design_object[2000];

   protected:
      interconnect_module_constraint_region();

   public:
      ~interconnect_module_constraint_region();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interconnect_module_constraint_region *InstanceOf(ARMObject *);
      static interconnect_module_constraint_region *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interconnect_module_constraint_region *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
