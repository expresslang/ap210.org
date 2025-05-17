#ifndef PACKAGE_TERMINAL_H
#define PACKAGE_TERMINAL_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <part_feature.h>

// Unions

// Enumerations

class AP210ARM_API package_terminal:
public part_feature
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 79};

   private:
      // Required attributes
      class connection_zone *_external_connection_zone[2000];
      class material_assembly_relationship *_terminal_surface_material;
      class material_assembly_relationship *_terminal_core_material;

      // Optional attributes
      class connection_zone *_internal_connection_zone[2000];
      class analytical_representation *_model_representation[2000];
      class characteristic *_terminal_characteristic[2000];
      class length_data_element *_minimum_terminal_diametrical_extent;
      class length_data_element *_maximum_terminal_diametrical_extent;

   protected:
      package_terminal();

   public:
      ~package_terminal();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static package_terminal *InstanceOf(ARMObject *);
      static package_terminal *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static package_terminal *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
