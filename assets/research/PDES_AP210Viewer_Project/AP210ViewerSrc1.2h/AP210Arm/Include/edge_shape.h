#ifndef EDGE_SHAPE_H
#define EDGE_SHAPE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <planar_shape.h>

// Unions

// Enumerations

class AP210ARM_API edge_shape:
public planar_shape
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 221};

   private:
      // Required attributes

      // Optional attributes

   protected:
      edge_shape();

   public:
      ~edge_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static edge_shape *InstanceOf(ARMObject *);
      static edge_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static edge_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
