#ifndef ASSEMBLY_COMPONENT_2D_SHAPE_H
#define ASSEMBLY_COMPONENT_2D_SHAPE_H

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

class AP210ARM_API assembly_component_2d_shape:
public managed_design_object
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 194};

   private:
      // Required attributes
      class assembly_component *_shape_characterized_component;

      // Optional attributes

   protected:
      assembly_component_2d_shape();

   public:
      ~assembly_component_2d_shape();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static assembly_component_2d_shape *InstanceOf(ARMObject *);
      static assembly_component_2d_shape *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static assembly_component_2d_shape *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
