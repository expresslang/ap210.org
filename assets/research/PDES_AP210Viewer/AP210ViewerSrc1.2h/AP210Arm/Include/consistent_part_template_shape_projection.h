#ifndef CONSISTENT_PART_TEMPLATE_SHAPE_PROJECTION_H
#define CONSISTENT_PART_TEMPLATE_SHAPE_PROJECTION_H

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

class AP210ARM_API consistent_part_template_shape_projection:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 391};

   private:
      // Required attributes
      class part_template_3d_shape *_projected_3d_shape;
      class part_template_planar_shape *_resultant_planar_shape;

      // Optional attributes

   protected:
      consistent_part_template_shape_projection();

   public:
      ~consistent_part_template_shape_projection();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static consistent_part_template_shape_projection *InstanceOf(ARMObject *);
      static consistent_part_template_shape_projection *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static consistent_part_template_shape_projection *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
