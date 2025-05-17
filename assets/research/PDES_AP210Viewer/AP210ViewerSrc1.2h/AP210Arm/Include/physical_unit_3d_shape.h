#ifndef PHYSICAL_UNIT_3D_SHAPE_H
#define PHYSICAL_UNIT_3D_SHAPE_H

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
#include <purpose.h>
#include <environment.h>

class AP210ARM_API physical_unit_3d_shape:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 235};

   private:
      // Required attributes
      class ee_requirement_occurrence *_application_technology_constraint;
      class bound_volume_shape *_shape_representation;
      class physical_unit *_shape_characterized_physical_unit;
      material_condition::material_condition _shape_material_condition;
      purpose::purpose _shape_purpose;
      environment::environment _shape_environment;

      // Optional attributes
      class cartesian_point *_centroid_location;

   protected:
      physical_unit_3d_shape();

   public:
      ~physical_unit_3d_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static physical_unit_3d_shape *InstanceOf(ARMObject *);
      static physical_unit_3d_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static physical_unit_3d_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
