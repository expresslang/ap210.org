#ifndef CARTESIAN_TRANSFORMATION_OPERATOR_2D_H
#define CARTESIAN_TRANSFORMATION_OPERATOR_2D_H

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

class AP210ARM_API cartesian_transformation_operator_2d:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 258};

   private:
      // Required attributes
      class orientation *_device_orientation;
      class cartesian_point *_translation;
      class positive_ratio_measure *_scale;

      // Optional attributes

   protected:
      cartesian_transformation_operator_2d();

   public:
      ~cartesian_transformation_operator_2d();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static cartesian_transformation_operator_2d *InstanceOf(ARMObject *);
      static cartesian_transformation_operator_2d *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static cartesian_transformation_operator_2d *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
