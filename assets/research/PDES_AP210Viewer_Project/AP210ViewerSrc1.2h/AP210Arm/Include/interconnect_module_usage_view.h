#ifndef INTERCONNECT_MODULE_USAGE_VIEW_H
#define INTERCONNECT_MODULE_USAGE_VIEW_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <physical_unit_usage_view.h>

// Unions

// Enumerations

class AP210ARM_API interconnect_module_usage_view:
public physical_unit_usage_view
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 600};

   private:
      // Required attributes

      // Optional attributes
      class length_data_element *_minimum_thickness_over_metal_requirement;
      class length_data_element *_maximum_thickness_over_metal_requirement;
      class length_data_element *_minimum_thickness_over_dielectric_requirement;
      class length_data_element *_maximum_thickness_over_dielectric_requirement;
      class restraint_condition *_measurement_condition;
      class located_interconnect_module_thickness_requirement *_located_thickness_requirement;
      class functional_unit_usage_view *_implemented_function;

   protected:
      interconnect_module_usage_view();

   public:
      ~interconnect_module_usage_view();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static interconnect_module_usage_view *InstanceOf(ARMObject *);
      static interconnect_module_usage_view *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static interconnect_module_usage_view *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
