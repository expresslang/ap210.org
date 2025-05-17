#ifndef STRATUM_FEATURE_PLANAR_SHAPE_H
#define STRATUM_FEATURE_PLANAR_SHAPE_H

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

class AP210ARM_API stratum_feature_planar_shape:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 808};

   private:
      // Required attributes
      class planar_projected_shape *_shape_representation;
      class stratum_feature *_represented_stratum_feature;

      // Optional attributes

   protected:
      stratum_feature_planar_shape();

   public:
      ~stratum_feature_planar_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static stratum_feature_planar_shape *InstanceOf(ARMObject *);
      static stratum_feature_planar_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static stratum_feature_planar_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
