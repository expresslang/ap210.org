#ifndef FEATURE_SHAPE_COMPOSITION_RELATIONSHIP_H
#define FEATURE_SHAPE_COMPOSITION_RELATIONSHIP_H

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

class AP210ARM_API feature_shape_composition_relationship:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 547};

   private:
      // Required attributes
      class feature_shape_occurrence *_related_feature_shape;
      class feature_shape_definition *_resultant_feature_shape;
      class axis_placement *_related_feature_shape_placement;

      // Optional attributes

   protected:
      feature_shape_composition_relationship();

   public:
      ~feature_shape_composition_relationship();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static feature_shape_composition_relationship *InstanceOf(ARMObject *);
      static feature_shape_composition_relationship *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static feature_shape_composition_relationship *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
