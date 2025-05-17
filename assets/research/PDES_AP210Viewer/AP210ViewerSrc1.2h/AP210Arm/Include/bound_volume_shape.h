#ifndef BOUND_VOLUME_SHAPE_H
#define BOUND_VOLUME_SHAPE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <feature_shape_definition.h>

// Unions

// Enumerations

class AP210ARM_API bound_volume_shape:
public feature_shape_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 40};

   private:
      // Required attributes

      // Optional attributes

   protected:
      bound_volume_shape();

   public:
      ~bound_volume_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static bound_volume_shape *InstanceOf(ARMObject *);
      static bound_volume_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static bound_volume_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
