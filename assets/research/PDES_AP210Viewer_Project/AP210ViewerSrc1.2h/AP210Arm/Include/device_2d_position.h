#ifndef DEVICE_2D_POSITION_H
#define DEVICE_2D_POSITION_H

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

class AP210ARM_API device_2d_position:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 486};

   private:
      // Required attributes
      class part_device *_placed_device;
      class axis_placement_2d *_transformation;
      class physical_unit_planar_shape *_part_shape;
      class physical_unit_planar_shape *_device_shape;

      // Optional attributes

   protected:
      device_2d_position();

   public:
      ~device_2d_position();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static device_2d_position *InstanceOf(ARMObject *);
      static device_2d_position *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static device_2d_position *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
