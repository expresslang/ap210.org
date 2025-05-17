#ifndef FEATURE_SHAPE_OCCURRENCE_H
#define FEATURE_SHAPE_OCCURRENCE_H

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

class AP210ARM_API feature_shape_occurrence:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 76};

   private:
      // Required attributes
      class feature_shape_definition *_instantiated_feature_shape;

      // Optional attributes

   protected:
      feature_shape_occurrence();

   public:
      ~feature_shape_occurrence();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static feature_shape_occurrence *InstanceOf(ARMObject *);
      static feature_shape_occurrence *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static feature_shape_occurrence *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
