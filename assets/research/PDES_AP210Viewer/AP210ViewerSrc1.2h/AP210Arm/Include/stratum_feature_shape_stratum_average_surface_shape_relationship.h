#ifndef STRATUM_FEATURE_SHAPE_STRATUM_AVERAGE_SURFACE_SHAPE_RELATIONSHIP_H
#define STRATUM_FEATURE_SHAPE_STRATUM_AVERAGE_SURFACE_SHAPE_RELATIONSHIP_H

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

class AP210ARM_API stratum_feature_shape_stratum_average_surface_shape_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 809};

   private:
      // Required attributes
      class stratum_feature_non_planar_2d_shape *_of_stratum_feature_shape;
      class stratum_average_surface_shape *_of_stratum_average_surface_shape;

      // Optional attributes

   protected:
      stratum_feature_shape_stratum_average_surface_shape_relationship();

   public:
      ~stratum_feature_shape_stratum_average_surface_shape_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_feature_shape_stratum_average_surface_shape_relationship *InstanceOf(ARMObject *);
      static stratum_feature_shape_stratum_average_surface_shape_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_feature_shape_stratum_average_surface_shape_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
