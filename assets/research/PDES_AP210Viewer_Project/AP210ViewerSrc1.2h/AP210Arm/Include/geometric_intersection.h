#ifndef GEOMETRIC_INTERSECTION_H
#define GEOMETRIC_INTERSECTION_H

// Setup for Windows dll
#ifdef AP210ARM_EXPORTS
#define AP210ARM_API __declspec(dllexport)
#else
#define AP210ARM_API __declspec(dllimport)
#endif

// Supertypes
#include <derived_shape_element.h>

// Unions

// Enumerations

class AP210ARM_API geometric_intersection:
public derived_shape_element
   {
   protected:
      // provide a typeid for run time type identification
      enum {typeID = baseID + 572};

   private:
      // Required attributes

      // Optional attributes

   protected:
      geometric_intersection();

   public:
      ~geometric_intersection();
      // runtime type identification
      virtual int DynamicType(int ID);
      virtual int getTypeID() {return typeID;};
      static int TypeID() {return typeID;};
      static geometric_intersection *InstanceOf(ARMObject *);
      static geometric_intersection *KindOf(ARMObject *);

   private:
      void initialize();

   public:

   // static functions
      // construction factory
      static geometric_intersection *Construct();


   // member functions
      // check for required attributes
      bool hasRequiredAttributes();
   };
#endif
