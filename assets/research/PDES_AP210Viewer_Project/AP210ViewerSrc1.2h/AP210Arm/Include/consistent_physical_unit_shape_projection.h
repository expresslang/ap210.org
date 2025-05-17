#ifndef CONSISTENT_PHYSICAL_UNIT_SHAPE_PROJECTION_H
#define CONSISTENT_PHYSICAL_UNIT_SHAPE_PROJECTION_H

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

class AP210ARM_API consistent_physical_unit_shape_projection:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 392};

   private:
      // Required attributes
      class physical_unit_3d_shape *_projected_3d_shape;
      class physical_unit_planar_shape *_resultant_planar_shape;

      // Optional attributes

   protected:
      consistent_physical_unit_shape_projection();

   public:
      ~consistent_physical_unit_shape_projection();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static consistent_physical_unit_shape_projection *InstanceOf(ARMObject *);
      static consistent_physical_unit_shape_projection *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static consistent_physical_unit_shape_projection *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
