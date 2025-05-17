#ifndef VOLUME_SHAPE_PROJECTION_H
#define VOLUME_SHAPE_PROJECTION_H

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

class AP210ARM_API volume_shape_projection:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 860};

   private:
      // Required attributes
      class planar_projected_shape *_surface_projection;
      class bound_volume_shape *_projected_volume;
      class axis_placement *_orientation_seating_plane;

      // Optional attributes

   protected:
      volume_shape_projection();

   public:
      ~volume_shape_projection();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static volume_shape_projection *InstanceOf(ARMObject *);
      static volume_shape_projection *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static volume_shape_projection *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
