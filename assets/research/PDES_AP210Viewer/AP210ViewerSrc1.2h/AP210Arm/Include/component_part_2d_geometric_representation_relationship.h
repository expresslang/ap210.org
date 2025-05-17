#ifndef COMPONENT_PART_2D_GEOMETRIC_REPRESENTATION_RELATIONSHIP_H
#define COMPONENT_PART_2D_GEOMETRIC_REPRESENTATION_RELATIONSHIP_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <part_template_or_physical_unit_2d_shape_select.h>

// Enumerations

class AP210ARM_API component_part_2d_geometric_representation_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 312};

   private:
      // Required attributes
      union part_template_or_physical_unit_2d_shape_select *_part_shape;
      class assembly_component_2d_shape *_component_shape;

      // Optional attributes

   protected:
      component_part_2d_geometric_representation_relationship();

   public:
      ~component_part_2d_geometric_representation_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static component_part_2d_geometric_representation_relationship *InstanceOf(ARMObject *);
      static component_part_2d_geometric_representation_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static component_part_2d_geometric_representation_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
