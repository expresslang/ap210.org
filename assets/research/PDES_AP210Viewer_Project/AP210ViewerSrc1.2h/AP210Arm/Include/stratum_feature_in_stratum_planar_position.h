#ifndef STRATUM_FEATURE_IN_STRATUM_PLANAR_POSITION_H
#define STRATUM_FEATURE_IN_STRATUM_PLANAR_POSITION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <managed_design_object.h>

// Unions
#include <stratum_feature_planar_representation_select.h>

// Enumerations

class AP210ARM_API stratum_feature_in_stratum_planar_position:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 805};

   private:
      // Required attributes
      class stratum_planar_shape *_stratum_shape;
      class axis_placement_2d *_transformation;
      union stratum_feature_planar_representation_select *_feature_shape;

      // Optional attributes

   protected:
      stratum_feature_in_stratum_planar_position();

   public:
      ~stratum_feature_in_stratum_planar_position();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_feature_in_stratum_planar_position *InstanceOf(ARMObject *);
      static stratum_feature_in_stratum_planar_position *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_feature_in_stratum_planar_position *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
