#ifndef FEATURE_SHAPE_DEFINITION_H
#define FEATURE_SHAPE_DEFINITION_H

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

class AP210ARM_API feature_shape_definition:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 41};

   private:
      // Required attributes
      class cartesian_coordinate_system *_geometric_context;

      // Optional attributes

   protected:
      feature_shape_definition();

   public:
      ~feature_shape_definition();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static feature_shape_definition *InstanceOf(ARMObject *);
      static feature_shape_definition *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static feature_shape_definition *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
