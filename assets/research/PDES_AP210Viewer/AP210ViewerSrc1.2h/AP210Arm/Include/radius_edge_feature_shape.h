#ifndef RADIUS_EDGE_FEATURE_SHAPE_H
#define RADIUS_EDGE_FEATURE_SHAPE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <edge_shape.h>

// Unions

// Enumerations

class AP210ARM_API radius_edge_feature_shape:
public edge_shape
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 747};

   private:
      // Required attributes
      class length_data_element *_minimum_radius_length;
      class length_data_element *_maximum_radius_length;

      // Optional attributes

   protected:
      radius_edge_feature_shape();

   public:
      ~radius_edge_feature_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static radius_edge_feature_shape *InstanceOf(ARMObject *);
      static radius_edge_feature_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static radius_edge_feature_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
