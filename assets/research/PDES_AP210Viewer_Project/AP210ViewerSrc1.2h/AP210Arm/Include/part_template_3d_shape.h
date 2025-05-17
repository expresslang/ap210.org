#ifndef PART_TEMPLATE_3D_SHAPE_H
#define PART_TEMPLATE_3D_SHAPE_H

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
#include <material_condition.h>
#include <environment.h>

class AP210ARM_API part_template_3d_shape:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 315};

   private:
      // Required attributes
      material_condition::material_condition _shape_material_condition;
      class bound_volume_shape *_shape_representation;
      class part_template *_shape_characterized_part_template;

      // Optional attributes
      environment::environment _shape_environment;

   protected:
      part_template_3d_shape();

   public:
      ~part_template_3d_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_template_3d_shape *InstanceOf(ARMObject *);
      static part_template_3d_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_template_3d_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
