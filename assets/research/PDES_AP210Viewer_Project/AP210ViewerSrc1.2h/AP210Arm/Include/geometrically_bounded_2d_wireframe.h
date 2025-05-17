#ifndef GEOMETRICALLY_BOUNDED_2D_WIREFRAME_H
#define GEOMETRICALLY_BOUNDED_2D_WIREFRAME_H

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

class AP210ARM_API geometrically_bounded_2d_wireframe:
public feature_shape_definition
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 575};

   private:
      // Required attributes

      // Optional attributes

   protected:
      geometrically_bounded_2d_wireframe();

   public:
      ~geometrically_bounded_2d_wireframe();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static geometrically_bounded_2d_wireframe *InstanceOf(ARMObject *);
      static geometrically_bounded_2d_wireframe *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static geometrically_bounded_2d_wireframe *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
