#ifndef GEOMETRICALLY_BOUNDED_SURFACE_H
#define GEOMETRICALLY_BOUNDED_SURFACE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <bound_volume_shape.h>

// Unions

// Enumerations

class AP210ARM_API geometrically_bounded_surface:
public bound_volume_shape
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 576};

   private:
      // Required attributes

      // Optional attributes

   protected:
      geometrically_bounded_surface();

   public:
      ~geometrically_bounded_surface();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static geometrically_bounded_surface *InstanceOf(ARMObject *);
      static geometrically_bounded_surface *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static geometrically_bounded_surface *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
