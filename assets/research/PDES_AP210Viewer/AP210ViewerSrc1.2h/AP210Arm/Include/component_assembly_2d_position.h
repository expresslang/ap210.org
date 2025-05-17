#ifndef COMPONENT_ASSEMBLY_2D_POSITION_H
#define COMPONENT_ASSEMBLY_2D_POSITION_H

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

class AP210ARM_API component_assembly_2d_position:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 296};

   private:
      // Required attributes
      class assembly_component_2d_shape *_component_model;
      class component_2d_location *_transformation;
      class physical_unit_planar_shape *_assembly_model;
      class next_higher_assembly_relationship *_component;

      // Optional attributes

   protected:
      component_assembly_2d_position();

   public:
      ~component_assembly_2d_position();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_assembly_2d_position *InstanceOf(ARMObject *);
      static component_assembly_2d_position *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_assembly_2d_position *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
