#ifndef PASSAGE_TECHNOLOGY_H
#define PASSAGE_TECHNOLOGY_H

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

class AP210ARM_API passage_technology:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 169};

   private:
      // Required attributes
      class inter_stratum_extent *_as_finished_inter_stratum_extent;
      RoseBoolean _plated_passage;
      STR _name;

      // Optional attributes
      class ee_material *_deposition_material;
      class length_data_element *_maximum_as_finished_passage_extent;
      class length_data_element *_minimum_as_finished_passage_extent;
      class length_data_element *_maximum_as_finished_deposition_thickness;
      double _maximum_aspect_ratio;
      class length_data_element *_minimum_as_finished_deposition_thickness;
      class process_specification *_specification;

   protected:
      passage_technology();

   public:
      ~passage_technology();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static passage_technology *InstanceOf(ARMObject *);
      static passage_technology *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static passage_technology *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
