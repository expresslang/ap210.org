#ifndef TANGENT_PLANE_H
#define TANGENT_PLANE_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <tangent_shape_element.h>

// Unions

// Enumerations

class AP210ARM_API tangent_plane:
public tangent_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 138};

   private:
      // Required attributes

      // Optional attributes

   protected:
      tangent_plane();

   public:
      ~tangent_plane();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static tangent_plane *InstanceOf(ARMObject *);
      static tangent_plane *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static tangent_plane *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
