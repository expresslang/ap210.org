#ifndef SETOFSTRATUM_FEATURE_PLANAR_SHAPE_H
#define SETOFSTRATUM_FEATURE_PLANAR_SHAPE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <ARMObject.h>

// Unions

// Enumerations

class AP210ARM_API SetOfstratum_feature_planar_shape:
virtual public ARMObject
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 807};

   private:
      // Required attributes
      class stratum_feature_planar_shape *_stratum_feature_planar_shape;

      // Optional attributes

   protected:
      SetOfstratum_feature_planar_shape();

   public:
      ~SetOfstratum_feature_planar_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static SetOfstratum_feature_planar_shape *InstanceOf(ARMObject *);
      static SetOfstratum_feature_planar_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static SetOfstratum_feature_planar_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
