#ifndef STRATUM_TECHNOLOGY_H
#define STRATUM_TECHNOLOGY_H

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
#include <stiffness_class.h>

class AP210ARM_API stratum_technology:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 29};

   private:
      // Required attributes
      class ee_material *_stratum_material;
      class length_data_element *_maximum_stratum_thickness;
      class length_data_element *_minimum_stratum_thickness;
      STR _name;

      // Optional attributes
      class length_data_element *_minimum_finished_feature_size;
      stiffness_class::stiffness_class _laminate_stiffness_class;
      class length_data_element *_minimum_finished_feature_spacing;
      class length_data_element *_maximum_feature_size_requirement;
      class process_specification *_specification;

   protected:
      stratum_technology();

   public:
      ~stratum_technology();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_technology *InstanceOf(ARMObject *);
      static stratum_technology *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_technology *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
