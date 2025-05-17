#ifndef PART_TEMPLATE_PLANAR_SHAPE_H
#define PART_TEMPLATE_PLANAR_SHAPE_H

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
#include <environment.h>
#include <material_condition.h>

class AP210ARM_API part_template_planar_shape:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 313};

   private:
      // Required attributes
      class part_template *_shape_characterized_part_template;
      class planar_projected_shape *_shape_representation;
      material_condition::material_condition _shape_material_condition;

      // Optional attributes
      environment::environment _shape_environment;

   protected:
      part_template_planar_shape();

   public:
      ~part_template_planar_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static part_template_planar_shape *InstanceOf(ARMObject *);
      static part_template_planar_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static part_template_planar_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
