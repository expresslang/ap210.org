#ifndef PLANAR_SHAPE_H
#define PLANAR_SHAPE_H

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

class AP210ARM_API planar_shape:
public feature_shape_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 222};

   private:
      // Required attributes

      // Optional attributes

   protected:
      planar_shape();

   public:
      ~planar_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static planar_shape *InstanceOf(ARMObject *);
      static planar_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static planar_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
